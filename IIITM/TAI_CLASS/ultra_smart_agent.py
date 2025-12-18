import random
from collections import deque

n = 19
m = 19
grid_size = n * m

# 0 = normal tile
# 1 = dirty tile
# 2 = sticky mud
# 3 = obstacle

grid = [[0 for _ in range(m)] for _ in range(n)]

d_t = 0.2
s_t = 0.1
obs_t = 0.2

def init_grid():
    d_c = s_c = obs_c = 0
    while d_c < (d_t * grid_size):
        x, y = random.randint(0, n-1), random.randint(0, m-1)
        if grid[x][y] != 0: continue
        grid[x][y] = 1
        d_c += 1

    while s_c < (s_t * grid_size):
        x, y = random.randint(0, n-1), random.randint(0, m-1)
        if grid[x][y] != 0: continue
        grid[x][y] = 2
        s_c += 1

    while obs_c < (obs_t * grid_size):
        x, y = random.randint(0, n-1), random.randint(0, m-1)
        if grid[x][y] != 0: continue
        grid[x][y] = 3
        obs_c += 1
    
    return d_c 


def print_grid():
    for i in range(n):
        for j in range(m):
            print(grid[i][j], end=" ")
        print()

directions = [
    (1,0,1.0), (-1,0,1.0), (0,1,1.0), (0,-1,1.0),
    (1,1,1.5), (-1,-1,1.5), (1,-1,1.5), (-1,1,1.5)
]

def bfs_find_path(start, target_val):
    visited = [[False]*m for _ in range(n)]
    q = deque([(start, [], 0)]) 
    visited[start[0]][start[1]] = True
    
    while q:
        (x,y), path, cost = q.popleft()
        if grid[x][y] == target_val:
            return path + [(x,y)], cost
        
        for dx,dy,move_cost in directions:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                if grid[nx][ny] != 3: 
                    extra = 2 if grid[nx][ny] == 2 else 0
                    visited[nx][ny] = True
                    q.append(((nx,ny), path+[(x,y)], cost+move_cost+extra))
    return None, None

def run_agent():
    energy = 100
    cleaned = 0
    total_energy_used = 0
    path_taken = []
    pos = (0,0)

    while energy > 0:
        path, cost = bfs_find_path(pos, 1)
        if not path: break
        if cost > energy: break
        
        # move along the path
        path_taken.extend(path[1:])
        energy -= cost
        total_energy_used += cost
        pos = path[-1]
        
        # clean
        if grid[pos[0]][pos[1]] == 1:
            grid[pos[0]][pos[1]] = 0
            cleaned += 1

    return cleaned, total_energy_used, path_taken

# ---- RUN ----
total_dirt = init_grid()
print_grid()
tiles_cleaned, energy_used, path_taken = run_agent()

path_grid = [["." for _ in range(m)] for _ in range(n)]
for (x,y) in path_taken:
    path_grid[x][y]="*"

print("\nResults:")
print("Tiles Cleaned:", tiles_cleaned)
print("Energy Used:", energy_used)
if energy_used > 0:
    print("Efficiency:", round(tiles_cleaned / energy_used, 4))
else:
    print("Efficiency: 0")
print("Coverage:", round(tiles_cleaned / total_dirt * 100, 2), "%")

# Show path map
for i in range(n):
    for j in range(m):
        print(path_grid[i][j], end=" ")
    print()

print("Final Room: ")
print_grid()