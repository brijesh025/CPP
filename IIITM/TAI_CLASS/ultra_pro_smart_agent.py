# Hybrid Exploration & Pathfinding Agent
# Deterministic / Stochastic 19x19 grid simulation
# Seed = 42
# Author: generated code to satisfy assignment requirements

import random
import heapq
from collections import deque, defaultdict

# -----------------------------
# Configuration / parameters
# -----------------------------
N = 19
M = 19
GRID_SIZE = N * M

DIRT_RATIO = 0.2
MUD_RATIO = 0.1
OBSTACLE_RATIO = 0.2

SEED = 42

# Energy and costs
START_ENERGY = 200.0
COST_HV = 1.0
COST_DIAG = 1.5
COST_MUD_EXTRA = 2.0
COST_CLEAN = 1.0

# Partial observability
OBS_RANGE = 2  # 5x5 area -> offsets -2..2

# Movement choices (dx, dy, base_cost)
MOVES = [
    (1, 0, COST_HV), (-1, 0, COST_HV), (0, 1, COST_HV), (0, -1, COST_HV),
    (1, 1, COST_DIAG), (-1, -1, COST_DIAG), (1, -1, COST_DIAG), (-1, 1, COST_DIAG)
]

# Map tile meanings
TILE_FREE = 0
TILE_DIRT = 1
TILE_MUD = 2
TILE_OBS = 3
TILE_UNKNOWN = -1  # used in memory map

random.seed(SEED)


# -----------------------------
# Utility functions
# -----------------------------
def in_bounds(x, y):
    return 0 <= x < N and 0 <= y < M


def init_grid(seed=SEED):
    random.seed(seed)
    grid = [[TILE_FREE for _ in range(M)] for _ in range(N)]

    total = N * M
    d_need = int(DIRT_RATIO * total)
    m_need = int(MUD_RATIO * total)
    o_need = int(OBSTACLE_RATIO * total)

    placed = {TILE_DIRT: 0, TILE_MUD: 0, TILE_OBS: 0}

    # Avoid placing obstacle at start (0,0)
    grid[0][0] = TILE_FREE

    while placed[TILE_DIRT] < d_need:
        x = random.randrange(N)
        y = random.randrange(M)
        if (x, y) == (0, 0): continue
        if grid[x][y] == TILE_FREE:
            grid[x][y] = TILE_DIRT
            placed[TILE_DIRT] += 1

    while placed[TILE_MUD] < m_need:
        x = random.randrange(N)
        y = random.randrange(M)
        if (x, y) == (0, 0): continue
        if grid[x][y] == TILE_FREE:
            grid[x][y] = TILE_MUD
            placed[TILE_MUD] += 1

    while placed[TILE_OBS] < o_need:
        x = random.randrange(N)
        y = random.randrange(M)
        if (x, y) == (0, 0): continue
        if grid[x][y] == TILE_FREE:
            grid[x][y] = TILE_OBS
            placed[TILE_OBS] += 1

    return grid, placed[TILE_DIRT]


def print_grid(grid):
    for i in range(N):
        for j in range(M):
            print(grid[i][j], end=" ")
        print()


# -----------------------------
# Observation / memory map
# -----------------------------
def observe_and_update_memory(real_grid, memory_map, pos):
    """Reveal a 5x5 area centered at pos and update memory_map in-place.
       Returns list of newly discovered dirt coordinates.
    """
    x0, y0 = pos
    discovered_dirt = []
    for dx in range(-OBS_RANGE, OBS_RANGE + 1):
        for dy in range(-OBS_RANGE, OBS_RANGE + 1):
            nx, ny = x0 + dx, y0 + dy
            if in_bounds(nx, ny):
                val = real_grid[nx][ny]
                if memory_map[nx][ny] == TILE_UNKNOWN and val == TILE_DIRT:
                    discovered_dirt.append((nx, ny))
                memory_map[nx][ny] = val
    return discovered_dirt


# -----------------------------
# Pathfinding on memory map (Dijkstra)
# -----------------------------
def dijkstra_on_memory(memory_map, start, goals):
    """Compute least-cost path from start to the nearest goal using known cells in memory_map.
       Unknown (-1) or obstacles (3) are treated as impassable.
       Returns (path_list start..goal inclusive, cost) or (None, None) if unreachable.
    """
    sx, sy = start
    # Priority queue: (cost, x, y)
    pq = [(0.0, sx, sy)]
    dist = [[float('inf')] * M for _ in range(N)]
    parent = [[None] * M for _ in range(N)]
    dist[sx][sy] = 0.0

    goal_set = set(goals)
    best_goal = None
    best_cost = float('inf')

    while pq:
        cost, x, y = heapq.heappop(pq)
        if cost > dist[x][y]:
            continue
        if (x, y) in goal_set:
            best_goal = (x, y)
            best_cost = cost
            break
        for dx, dy, base in MOVES:
            nx, ny = x + dx, y + dy
            if not in_bounds(nx, ny):
                continue
            tile = memory_map[nx][ny]
            if tile == TILE_UNKNOWN or tile == TILE_OBS:
                continue
            extra = COST_MUD_EXTRA if tile == TILE_MUD else 0.0
            ncost = cost + base + extra
            if ncost < dist[nx][ny]:
                dist[nx][ny] = ncost
                parent[nx][ny] = (x, y)
                heapq.heappush(pq, (ncost, nx, ny))

    if best_goal is None:
        return None, None

    # reconstruct path
    path = []
    cur = best_goal
    while cur is not None:
        path.append(cur)
        cur = parent[cur[0]][cur[1]]
    path.reverse()
    return path, best_cost


# -----------------------------
# Helper to compute move cost between two adjacent coordinates
# -----------------------------
def move_cost_between(a, b, grid):
    ax, ay = a
    bx, by = b
    dx = bx - ax
    dy = by - ay
    base = COST_DIAG if abs(dx) == 1 and abs(dy) == 1 else COST_HV
    extra = COST_MUD_EXTRA if grid[bx][by] == TILE_MUD else 0.0
    return base + extra


# -----------------------------
# Stochastic movement handler
# -----------------------------
def sample_actual_move(intended_dx, intended_dy, deterministic=True):
    """Return actual (dx,dy) after stochastic slip if deterministic=False.
       Slip model:
         - 80% intended
         - 10% slip to left-diagonal
         - 10% slip to right-diagonal
       Interpretation:
         - For axial intended moves (1,0), left/right diagonals are (1,-1) and (1,1)
         - For diagonal intended moves (1,1), slips go to (1,0) and (0,1) (the orthogonal components)
    """
    if deterministic:
        return intended_dx, intended_dy

    r = random.random()
    if r < 0.8:
        return intended_dx, intended_dy
    # define left and right slips
    dx, dy = intended_dx, intended_dy
    if abs(dx) + abs(dy) == 1:  # axial
        # left diag: keep axis component, add -1/1 on other axis
        left = (dx, dy - 1) if dy == 0 else (dx - 1, dy)
        right = (dx, dy + 1) if dy == 0 else (dx + 1, dy)
        # but ensure values in {-1,0,1}
        left = (max(-1, min(1, left[0])), max(-1, min(1, left[1])))
        right = (max(-1, min(1, right[0])), max(-1, min(1, right[1])))
        if r < 0.9:
            return left
        else:
            return right
    else:  # diagonal (dx,dy both non-zero)
        # slip to orthogonal components
        candidates = [(dx, 0), (0, dy)]
        if r < 0.9:
            return candidates[0]
        else:
            return candidates[1]


# -----------------------------
# Exploration utilities (DFS frontier)
# -----------------------------
def known_neighbors(memory_map, x, y):
    for dx, dy, _ in MOVES:
        nx, ny = x + dx, y + dy
        if in_bounds(nx, ny):
            yield nx, ny


def find_frontiers(memory_map):
    """Return list of known cells that have at least one UNKNOWN neighbor"""
    frontiers = []
    for i in range(N):
        for j in range(M):
            if memory_map[i][j] == TILE_UNKNOWN or memory_map[i][j] == TILE_OBS:
                continue
            # must be walkable known cell
            for nx, ny in known_neighbors(memory_map, i, j):
                if memory_map[nx][ny] == TILE_UNKNOWN:
                    frontiers.append((i, j))
                    break
    return frontiers


# -----------------------------
# Main agent loop
# -----------------------------
def run_agent(real_grid, deterministic=True):
    memory_map = [[TILE_UNKNOWN for _ in range(M)] for _ in range(N)]
    pos = (0, 0)
    energy = START_ENERGY

    # initialize observation
    discover = observe_and_update_memory(real_grid, memory_map, pos)

    # Track stats
    total_dirt = sum(1 for i in range(N) for j in range(M) if real_grid[i][j] == TILE_DIRT)
    cleaned_tiles = 0
    energy_used = 0.0
    path_taken = [pos]  # record visited cells in order

    # DFS stack: holds known walkable cells to continue exploration from (LIFO)
    dfs_stack = deque()
    dfs_stack.append(pos)
    visited_for_dfs = set([pos])

    # Known dirt set (from memory)
    known_dirt = set()
    for (x, y) in discover:
        known_dirt.add((x, y))

    # Main loop
    steps = 0
    while energy > 0:
        steps += 1
        # Observe at current position (each time we move we should observe)
        newly = observe_and_update_memory(real_grid, memory_map, pos)
        for d in newly:
            known_dirt.add(d)

        # Clean if on a dirty tile and enough energy
        px, py = pos
        if memory_map[px][py] == TILE_DIRT and real_grid[px][py] == TILE_DIRT:
            # Clean
            if energy < COST_CLEAN:
                break
            energy -= COST_CLEAN
            energy_used += COST_CLEAN
            cleaned_tiles += 1
            real_grid[px][py] = TILE_FREE
            memory_map[px][py] = TILE_FREE
            if (px, py) in known_dirt:
                known_dirt.remove((px, py))
            # after cleaning, continue
            continue

        # If there are known dirt tiles, decide whether to go clean nearest
        if known_dirt:
            # get nearest dirt by path cost on memory_map
            path_to_dirt, cost_to_dirt = dijkstra_on_memory(memory_map, pos, known_dirt)
            if path_to_dirt is not None:
                # total required energy: path movement cost + cleaning cost
                required = cost_to_dirt + COST_CLEAN
                if required <= energy:
                    # switch to pathfinding mode: execute path step-by-step
                    # path includes current pos; iterate over next steps
                    for k in range(1, len(path_to_dirt)):
                        nx, ny = path_to_dirt[k]
                        intended_dx = nx - pos[0]
                        intended_dy = ny - pos[1]
                        actual_dx, actual_dy = sample_actual_move(intended_dx, intended_dy, deterministic)
                        ax = pos[0] + actual_dx
                        ay = pos[1] + actual_dy
                        if not in_bounds(ax, ay) or real_grid[ax][ay] == TILE_OBS:
                            # slip leads to invalid/obstacle -> stay in place (no movement cost)
                            # We still observe surroundings
                            observe_and_update_memory(real_grid, memory_map, pos)
                            path_taken.append(pos)
                            continue
                        # move to actual cell
                        step_cost = move_cost_between(pos, (ax, ay), real_grid)
                        if step_cost > energy:
                            # can't perform this movement, stop execution
                            energy = 0
                            break
                        energy -= step_cost
                        energy_used += step_cost
                        pos = (ax, ay)
                        path_taken.append(pos)
                        # observe at new position
                        newly2 = observe_and_update_memory(real_grid, memory_map, pos)
                        for d in newly2:
                            known_dirt.add(d)
                    # after moving along path, loop will continue and clean if on dirt
                    continue
                # else, cannot reach due to energy; fall through to exploration mode
        # Exploration Mode (DFS): pick a frontier cell (DFS behaviour)
        frontiers = find_frontiers(memory_map)
        if not frontiers and not known_dirt:
            # No frontiers and no known dirt -> exploration complete
            break

        # ensure dfs_stack contains useful nodes: if empty, add frontiers
        if not dfs_stack:
            # push all frontiers to stack (to allow DFS ordering)
            for f in frontiers:
                if f not in visited_for_dfs:
                    dfs_stack.append(f)
                    visited_for_dfs.add(f)

        # pop next DFS target; ensure reachable
        next_target = None
        while dfs_stack:
            candidate = dfs_stack.pop()
            # ensure candidate still has unknown neighbor
            cx, cy = candidate
            still_frontier = False
            for nx, ny in known_neighbors(memory_map, cx, cy):
                if memory_map[nx][ny] == TILE_UNKNOWN:
                    still_frontier = True
                    break
            if not still_frontier:
                continue
            # check reachability via memory_map (we only plan on known cells)
            path_to_frontier, cost_to_frontier = dijkstra_on_memory(memory_map, pos, [candidate])
            if path_to_frontier is not None and cost_to_frontier <= energy:
                next_target = candidate
                break
            # if not reachable or too expensive, skip (but keep exploring other nodes)
        if next_target is None:
            # no reachable frontier (maybe there are unknowns but not reachable with known map)
            # try to expand dfs by adding neighbors of known walkable cells
            for i in range(N):
                for j in range(M):
                    if memory_map[i][j] in (TILE_FREE, TILE_MUD, TILE_DIRT) and (i, j) not in visited_for_dfs:
                        # push this known cell to DFS stack
                        dfs_stack.append((i, j))
                        visited_for_dfs.add((i, j))
            # if still no next_target then break
            if not dfs_stack:
                break
            else:
                continue

        # Travel to DFS target (next_target) using shortest path on known memory map
        path_to_frontier, cost_to_frontier = dijkstra_on_memory(memory_map, pos, [next_target])
        if path_to_frontier is None:
            continue  # not reachable after all
        # execute move along path step-by-step (similar to above)
        for k in range(1, len(path_to_frontier)):
            nx, ny = path_to_frontier[k]
            intended_dx = nx - pos[0]
            intended_dy = ny - pos[1]
            actual_dx, actual_dy = sample_actual_move(intended_dx, intended_dy, deterministic)
            ax = pos[0] + actual_dx
            ay = pos[1] + actual_dy
            if not in_bounds(ax, ay) or real_grid[ax][ay] == TILE_OBS:
                observe_and_update_memory(real_grid, memory_map, pos)
                path_taken.append(pos)
                continue
            step_cost = move_cost_between(pos, (ax, ay), real_grid)
            if step_cost > energy:
                energy = 0
                break
            energy -= step_cost
            energy_used += step_cost
            pos = (ax, ay)
            path_taken.append(pos)
            # observe at new position
            newly3 = observe_and_update_memory(real_grid, memory_map, pos)
            for d in newly3:
                known_dirt.add(d)

        # continue main loop

    # compute metrics
    explored_count = sum(1 for i in range(N) for j in range(M) if memory_map[i][j] != TILE_UNKNOWN)
    percent_explored = (explored_count / GRID_SIZE) * 100.0
    coverage = (cleaned_tiles / total_dirt * 100.0) if total_dirt > 0 else 0.0
    efficiency = (cleaned_tiles / energy_used) if energy_used > 0 else 0.0

    return {
        'tiles_cleaned': cleaned_tiles,
        'energy_used': energy_used,
        'efficiency': efficiency,
        'coverage_percent': coverage,
        'percent_explored': percent_explored,
        'path_taken': path_taken,
        'final_real_grid': real_grid,
        'memory_map': memory_map,
        'total_initial_dirt': total_dirt
    }


# -----------------------------
# Pretty printing results
# -----------------------------
def show_path_map(path_taken):
    path_grid = [["." for _ in range(M)] for _ in range(N)]
    for (x, y) in path_taken:
        path_grid[x][y] = "*"
    for i in range(N):
        for j in range(M):
            print(path_grid[i][j], end=" ")
        print()


def run_and_print(deterministic=True):
    mode = "Deterministic" if deterministic else "Stochastic (80% intended, 10% left-diag, 10% right-diag)"
    print("Mode:", mode)
    # initialize fresh grid for each run
    real_grid, total_dirt = init_grid(SEED)  # deterministic seeding ensures same layout
    print("Initial real grid (legend 0=free,1=dirt,2=mud,3=obstacle):")
    print_grid(real_grid)
    print(f"Total initial dirt tiles: {total_dirt}")
    print("\nRunning agent...\n")
    result = run_agent(real_grid, deterministic=deterministic)
    print("---- RESULTS ----")
    print("Tiles Cleaned:", result['tiles_cleaned'])
    print("Energy Used:", round(result['energy_used'], 4))
    print("Efficiency (tiles cleaned / energy):", round(result['efficiency'], 6))
    print("Coverage (percent of initial dirt cleaned):", round(result['coverage_percent'], 4), "%")
    print("Percentage of map explored:", round(result['percent_explored'], 4), "%")
    print("\nPath taken (map): '*' visited cells, '.' others")
    show_path_map(result['path_taken'])
    print("\nFinal real grid (after cleaning):")
    print_grid(result['final_real_grid'])


# -----------------------------
# Main execution - runs both settings
# -----------------------------
if __name__ == "__main__":
    # Run deterministic version
    run_and_print(deterministic=True)
    print("\n\n========================\n\n")
    # For stochastic, re-seed to have deterministic randomness for fair comparison
    random.seed(SEED)
    run_and_print(deterministic=False)
