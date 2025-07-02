// A.Dijkstra's Algo // Using Que TC==>O(V^2)
// #include <bits/stdc++.h>
// using namespace std;
// const int MAX_V = 1e5;
// vector<pair<int, int>> graph[MAX_V];
// vector<int> visited(MAX_V, 0);
// void dijkstra(int src, vector<int> &distance) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //using Proiority Queue TC==>O(ElogV)
//     q.push(make_pair(0, src));
//     distance[src] = 0;
//     while (!q.empty()) {
//         int crnt_dist = q.top().first;
//         int crnt = q.top().second;
//         q.pop();
//         if (visited[crnt]) continue;
//         visited[crnt] = 1;
//         for (auto &neighbour : graph[crnt]) {
//             int neighbour_v = neighbour.first;
//             int wt = neighbour.second;
//             if (crnt_dist + wt < distance[neighbour_v]) {
//                 distance[neighbour_v] = crnt_dist + wt;
//                 q.push(make_pair(distance[neighbour_v], neighbour_v));
//             }
//         }
//     }
// }
// int main() {
//     int v, e;
//     cin >> v >> e;
//     for (int i = 0; i < e; i++) {
//         int src, des, wt;
//         cin >> src >> des >> wt;
//         graph[src].push_back({des, wt});
//     }
//     vector<int> distance(v + 1, INT_MAX);
//     dijkstra(1, distance);
//     for (int i = 1; i <= v; i++) {
//         if (distance[i] == INT_MAX) {
//             cout << i << " -> " << "INF" << endl;
//         } else {
//             cout << i << " -> " << distance[i] << endl;
//         }
//     }
//     return 0;
// }

// B.MST

// 1.PRIMS'S ALGO--> TC-->O(ElogV){adjency list} and O(V^2){adjency matrix}
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int v;
//     cin>>v;
//     vector<vector<pair<int,int>>> graph(v);
//     for(int i=0;i<v;i++) {
//         int src,des,weight;
//         cin>>src>>des>>weight;
//         graph[src].push_back({weight,des});
//         graph[des].push_back({weight,src});
//     }
//     vector<pair<int,int>> mst;
//     int sum=0;
//     priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
//     pq.push({0, {0, -1}});
//     vector<int> vis(v);
//     while(!pq.empty()){
//         int weight=pq.top().first;
//         int crnt_vrtx=pq.top().second.first;
//         int parent=pq.top().second.second;
//         pq.pop();
//         if(vis[crnt_vrtx])continue;
//         vis[crnt_vrtx]=1;
//         if(parent!=-1){
//             sum+=weight;
//             mst.push_back({crnt_vrtx,parent});
//         }
//         for(auto nbr:graph[crnt_vrtx]){
//             if(!vis[nbr.second])pq.push({nbr.first,{nbr.second,crnt_vrtx}});
//         }
//     }
//     for(auto i:mst){
//         cout<<i.first<<" "<<i.second<<endl;
//     }
//     cout<<sum;
// return 0;
// }

// 2.KRUSKAL'S ALGO---> TC--> O(ElogE){adjency list} and O(V^2){adjency matrix}
// #include <bits/stdc++.h>
// using namespace std;
// int f_parent(int node,vector<int>&parent){
//     if(parent[node]==node)return node;
//     return parent[node]=f_parent(parent[node],parent);
// }
// void union_set(vector<int>&parent,vector<int>&rank,int v,int u){
//     int u_root=f_parent(u,parent);
//     int v_root=f_parent(v,parent);
//     if(rank[u_root]<rank[v_root])parent[u_root]=v_root;
//     else if(rank[u_root]>rank[v_root])parent[v_root]=u_root;
//     else{
//         parent[v_root]=u_root;
//         rank[u_root]++;
//     }
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     vector<pair<int,pair<int,int>>> graph(e);
//     vector<int> parent(v);
//     vector<int> rank(v,0);
//     for(int i=0;i<e;i++){
//         parent[i]=i;
//         int src,des,weight;
//         cin>>src>>des>>weight;
//         graph[i]={weight,{src,des}};
//     }
//     sort(graph.begin(),graph.end());
//     int sum=0;
//     vector<pair<int,int>> mst;
//     for(auto i:graph){
//         int src=i.second.first;
//         int des=i.second.second;
//         if(f_parent(src,parent)!=f_parent(des,parent)){
//             sum+=i.first;
//             mst.push_back({src,des});
//             union_set(parent,rank,src,des);
//         }
//     }
//     for(auto i:mst){
//         cout<<i.first<<" "<<i.second<<endl;
//     }
//     cout<<sum;
// return 0;
// }

// C.FLOYD WARSHAL ALGORITHM --> TC=O(V^3) AND SC=O(V^2)

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int v;
//     cin>>v;
//     vector<vector<int>> graph(v,vector<int>(v,INT_MAX));
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             cin>>graph[i][j];
//         }
//     }
//     for(int vai=0;vai<v;vai++){
//         for(int i=0;i<v;i++){
//             for(int j=0;j<v;j++){
//                 graph[i][j]=min(graph[i][j],graph[i][vai]+graph[vai][j]);
//             }
//         }
//     }
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             if(graph[i][j]==INT_MAX)cout<<"INF ";
//             else cout<<graph[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// return 0;
// }

// D.TOPOLOGICAL SORT ALGORITHM

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool>& visited, stack<int>& s, vector<vector<int>>& adj) {
    visited[node] = true;
    for (int nbr : adj[node])
        if (!visited[nbr])
            dfs(nbr, visited, s, adj);
    s.push(node);
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; ++i) {
        int u, vtx;
        cin >> u >> vtx;
        adj[u].push_back(vtx);
    }
    stack<int> s;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; ++i)
        if (!visited[i])
            dfs(i, visited, s, adj);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
