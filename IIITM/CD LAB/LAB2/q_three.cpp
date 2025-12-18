#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int start;
    int end;
};

int minimumTimeToReach(int n, vector<vector<int>> &edges) {
    vector<vector<Edge>> graph(n);
    for (auto &e : edges) {
        // edges are: from, to, start, end
        graph[e[0]].push_back({e[1], e[2], e[3]});
    }

    const int MAXT = 1000;
    vector<vector<bool>> visited(n, vector<bool>(MAXT, false));

    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int node = current.first;
        int time = current.second;

        if (node == n - 1) return time;

        // wait
        if (time + 1 < MAXT && !visited[node][time + 1]) {
            visited[node][time + 1] = true;
            q.push({node, time + 1});
        }

        // traverse available edges
        for (auto &edge : graph[node]) {
            if (time >= edge.start && time <= edge.end) {
                if (time + 1 < MAXT && !visited[edge.to][time + 1]) {
                    visited[edge.to][time + 1] = true;
                    q.push({edge.to, time + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    if (!(cin >> n)) return 0;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(4));
    cout << "Enter edges in format: from to start end\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
    }

    int answer = minimumTimeToReach(n, edges);
    if (answer == -1) {
        cout << "It is impossible to reach node " << n - 1 << endl;
    } else {
        cout << "Minimum time to reach node " << n - 1 << " is: " << answer << endl;
    }
    cout<<"2023-IMT025 BRIJESH SINGH";

    return 0;
}
