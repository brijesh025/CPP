// A.UNWEIGHTED GRAPH

// 1.ADJENCY LIST

// i.USING STL
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
// int main(){
//     cin>>v_cnt>>e_cnt;
//     graph.resize(v_cnt,list<int>());
//     while(e_cnt--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     display();
// return 0;
// }

// ii. WITHOUT STL
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node *next;
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
// };
// class linked_list{
//     public:
//     node* head;
//     linked_list(){
//         head=nullptr;
//     }
//     void push_back(int data){
//         node *new_node=new node(data);
//         if(head==nullptr){
//             head=new_node;
//             return;
//         }
//         node* temp=head;
//         while(temp->next)temp=temp->next;
//         temp->next=new_node;
//         return;
//     }
// };
// linked_list graph[INT16_MAX];
// void add_edge(int src,int des,bool bidir=true){
//     graph[src].push_back(des);
//     if(bidir) graph[des].push_back(src);
// }
// void display(int v){
//     for(int i=0;i<v;i++){
//         node* temp=graph[i].head;
//         cout<<i<<"->";
//         while(temp){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     while(v--){
//         int src,des;
//         cin>>src>>des;
//         add_edge(src,des);
//     }
//     display(7);
// return 0;
// }

// B.WEIGHTED GRAPH

// i.WITH STL

// 1.ADJENCY LIST
//  #include <bits/stdc++.h>
//  using namespace std;
//  vector<list<pair<int,int>>> graph;
//  int v_cnt,e_cnt;
//  void add_edge(int src_v,int dest_v,int weight,bool bi_dir=true){
//     graph[src_v].push_back({weight,dest_v});
//     if(bi_dir){
//         graph[dest_v].push_back({weight,src_v});
//     }
//  }
//  void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<" -> ";
//         for(auto j:graph[i]){
//             cout<<"("<<j.first<<","<<j.second<<")"<<" ";
//         }
//         cout<<endl;
//     }
//  }
// int main(){
//     cin>>v_cnt>>e_cnt;
//     graph.resize(v_cnt,list<pair<int,int>>());
//     while(e_cnt--){
//         int s,weight,d;
//         cin>>s>>weight>>d;
//         add_edge(s,d,weight);
//     }
//     display();
// return 0;
// }

// 2.ADJENCY MAP
 #include <bits/stdc++.h>
 using namespace std;
 int MAX= numeric_limits<int>::max();
 vector<vector<int>> graph;
 int v_cnt,e_cnt;
 void add_edge(int src_v,int dest_v,int weight,bool bi_dir=true){
    graph[src_v][dest_v]=weight;
    if(bi_dir){
        graph[dest_v][src_v]=weight;
    }
 }
 void display(){
    for(int i=0;i<v_cnt;i++){
        cout<<i<<" -> ";
        for(int j=0;j<v_cnt;j++){
            cout << (graph[i][j] == MAX ? "INF" : to_string(graph[i][j])) << " ";
        }
        cout<<endl;
    }
 }
int main(){
    cin>>v_cnt>>e_cnt;
    graph.resize(v_cnt,vector<int>(v_cnt,MAX));
    while(e_cnt--){
        int s,d,weight;
        cin>>s>>d>>weight;
        add_edge(s,d,weight);
    }
    display();
return 0;
}

// ii.WITHOUT STL

// 1.ADJENCY MAP
//  #include <bits/stdc++.h>
// using namespace std;

// const int MAX_V = 100; // Adjust size as needed
// int graph[MAX_V][MAX_V];
// bool visited[MAX_V];
// int v; // Number of vertices

// void dfs(int crnt) {
//     cout << crnt << " ";
//     visited[crnt] = true;
//     for (int i = 0; i < v; i++) {
//         if (graph[crnt][i] == 1 && !visited[i]) {
//             dfs(i);
//         }
//     }
// }
// void bfs(int src){
//     queue <int> q;
//     q.push(src);
//     visited[src]=1;
//     while(!q.empty()){
//         int crnt=q.front();
//         q.pop();
//         cout<<crnt<<" ";
//         for(int i=0;i<v;i++){
//             if(graph[crnt][i]==1 and visited[i]==0){
//                 q.push(i);
//                 visited[i]=1;
//             }
//         }
//     }
// }
// int main() {
//     // Initialize graph and visited here
//     // Example initialization
//     v = 5; // Example number of vertices
//     graph[0][1] = graph[1][0] = 1;
//     graph[0][2] = graph[2][0] = 1;
//     graph[1][3] = graph[3][1] = 1;
//     graph[2][4] = graph[4][2] = 1;

//     // Initialize visited array
//     for (int i = 0; i < v; i++) {
//         visited[i] = false;
//     }

//     // Call dfs starting from vertex 0
//     dfs(0);
//     for (int i = 0; i < v; i++) {
//         visited[i] = false;
//     }
//     cout<<endl;
//     bfs(0);
//     return 0;
// }