#include <bits/stdc++.h>
using namespace std;

bool chkHam(vector<vector<int>> &graph, vector<int> &path, int node) {
    if (path.size() == graph.size()) {
        if (find(graph[node].begin(), graph[node].end(), 0) != graph[node].end()) {
            path.push_back(0);
            return true;
        }
        return false;
    }
    for (auto nbr : graph[node]) {
        if (find(path.begin(), path.end(), nbr) == path.end()) {
            path.push_back(nbr);
            if (chkHam(graph, path, nbr)) return true;
            path.pop_back();
        }
    }
    return false;
}

void display(vector<vector<int>> &graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++) {
        int src, des;
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    display(graph);
    
    vector<int> path = {0}; // Start from node 0
    if (chkHam(graph, path, 0)) {
        cout << "YES" << endl;
        for (auto i : path) cout << i << " ";
    } else cout << "NO" << endl;
    
    return 0;
}
