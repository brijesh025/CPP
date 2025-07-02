#include <bits/stdc++.h>
using namespace std;
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> color(v, -1);
    for (int u = 0; u < v; ++u) {
        set<int> used;
        for (int nbr : graph[u])
            if (color[nbr] != -1)
                used.insert(color[nbr]);
        int clr_v = 0;
        while (used.count(clr_v)) clr_v++;
        color[u] = clr_v;
    }
    int max_color = *max_element(color.begin(), color.end());
    cout << "Chromatic Number: " << max_color + 1 << endl;
    return 0;
}
