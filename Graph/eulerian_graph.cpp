// 1.CHECK EULER GRAPH OR NOT
//  #include <bits/stdc++.h>
//  using namespace std;
//  vector<list<int>> graph;
//  int v_cnt,e_cnt;
//  void add_edge(int src_v,int dest_v,bool bi_dir=true){
//     graph[src_v].push_back(dest_v);
//     if(bi_dir){
//         graph[dest_v].push_back(src_v);
//     }
//  }
//  void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<" -> ";
//         for(auto j:graph[i]){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//  }
//  void check(){
//     int cnt=0;
//     for(auto i:graph){
//         if(i.size()%2!=0)cnt++;
//     }
//     if(cnt==0)cout<<"EULER"<<endl;
//     else if(cnt==2)cout<<"SEMI-EULER"<<endl;
//     else cout<<"NOT EULER";
//  }
// int main(){
//     cin>>v_cnt>>e_cnt;
//     graph.resize(v_cnt,list<int>());
//     while(e_cnt--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     display();
//     check();
// return 0;
// }


// 2.CHECK IF CONTAINS EULER CYCLE, EULER PATH OR NONE
#include <bits/stdc++.h>
using namespace std;
string eulerType(vector<vector<int>>& graph) {
    int odd = 0;
    for (int i = 0; i < graph.size(); ++i)
        if (graph[i].size() % 2 != 0)
            ++odd;
    if (odd == 0) return "Euler Cycle";
    if (odd == 2) return "Euler Path";
    return "None";
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    while (e--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << eulerType(graph) << endl;
    return 0;
}
