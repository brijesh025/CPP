#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
void add_edge(int src, int des, bool bi_dir = 1) {
    graph[src].push_back(des);
    if (bi_dir) graph[des].push_back(src);
}
void display() {
    int size = graph.size();
    for (int i = 0; i < size; i++) {
        cout << i << "-> ";
        for (auto nbr : graph[i]) cout << nbr << " ";
        cout << endl;
    }
}
bool chkBipartite(int v,int e) {
    vector<int> color(v, -1);
    bool isBipartite = true;
    for (int i = 0; i < v; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto nbr : graph[node]) {
                    if (color[nbr] == -1) {
                        color[nbr] = 1 - color[node];
                        q.push(nbr);
                    } else if (color[nbr] == color[node]) {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }
    }
    return isBipartite;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e;
    cin >> v >> e;
    graph.resize(v);
    for (int i = 0; i < e; i++) {
        int src, des;
        cin >> src >> des;
        add_edge(src, des);
    }
    display();

    if (chkBipartite(v,e)) {
        cout << "Graph can be colored using two colors." << endl;
    } else {
        cout << "Graph cannot be colored using two colors." << endl;
    }

    return 0;
}