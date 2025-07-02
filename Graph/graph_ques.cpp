// 1.PATHS IN GRAPH
// #include <bits/stdc++.h>
// using namespace std;
// class node {
// public:
//     int val;
//     node *next;
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
// };
// class linked_list {
// public:
//     node* head;
//     linked_list() : head(nullptr) {}
//     void push_back(int data) {
//         node *new_node = new node(data);
//         if (head == nullptr) {
//             head = new_node;
//         } else {
//             node* temp = head;
//             while (temp->next) temp = temp->next;
//             temp->next = new_node;
//         }
//     }
// };
// linked_list graph[INT16_MAX];
// set<int> visited;
// vector<vector<int>> all_path;
// void add_edge(int src, int des, bool bidir = true) {
//     graph[src].push_back(des);
//     if (bidir) graph[des].push_back(src);
// }
// void display(int v) {
//     for (int i = 0; i < v; i++) {
//         node* temp = graph[i].head;
//         cout << i << "->";
//         while (temp) {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// }
// void find_path(int crnt, int des, vector<int> &path) {
//     if(crnt==des){
//         path.push_back(crnt);
//         all_path.push_back(path);
//         path.pop_back();
//         return;
//     }
//     visited.insert(crnt);
//     path.push_back(crnt);
//         node* temp = graph[crnt].head;
//         while (temp) {
//             if (!visited.count(temp->val)) {
//                 find_path(temp->val, des, path);
//             }
//             temp = temp->next;
//         }
//     path.pop_back();
//     visited.erase(crnt);
//     return;
// }
// bool any_path(int src, int des) {
//     if (src == des) return true;  // Base case: source is destination.
//     visited.insert(src);  // Mark the current node as visited.
//     node* temp = graph[src].head;  // Start with the head of the linked list for the source node.
//     while (temp) {
//         if (!visited.count(temp->val)) {  // Check if the node has not been visited.
//             if (any_path(temp->val, des)) {  // Recursively check for path from the current node to destination.
//                 return true;  // If a path is found, return true immediately.
//             }
//         }
//         temp = temp->next;  // Move to the next node in the adjacency list.
//     }
//     return false;  // If no path is found after checking all nodes, return false.
// }
// void find_all_path(int src, int des) {
//     vector<int> path;
//     find_path(src, des, path);
// }
// vector <int> shortest_path(int src,int v){
//     vector<int> distance(v,INT16_MAX);
//     queue<int> q;
//     q.push(src);
//     distance[src]=0;
//     while(!q.empty()){
//         node* adj_node=graph[q.front()].head;
//         int crnt_node_dis=distance[q.front()];
//         q.pop();
//         while(adj_node){
//             if(crnt_node_dis+1<distance[adj_node->val]){
//                 distance[adj_node->val]=crnt_node_dis+1;
//                 q.push(adj_node->val);
//             }
//             adj_node=adj_node->next;
//         }
//     }
//     return distance;
// }
// int main() {
//     int v, e;
//     cin >> v >> e;
//     while (e--) {
//         int src, des;
//         cin >> src >> des;
//         add_edge(src, des);
//     }
//     display(v);
//     // find_all_path(0, 2);
//     // for (auto &i : all_path) {
//     //     for (int j : i) cout << j << " ";
//     //     cout << endl;
//     // }
//     // cout<<any_path(0,2);
//     vector<int> distance=shortest_path(0,7);
//     for(int i=0;i<v;i++){
//         cout<<i<<"->"<<distance[i]<<endl;
//     }
//     return 0;
// }

// 2.NO. OF CONNECTED COMPONENTS
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX_INT 100
// class node{
//     public:
//     int val;
//     node* next;
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
//         node* new_node=new node(data);
//         if(head==nullptr){
//             head=new_node;
//             return;
//         }
//         node* temp=head;
//         while(temp->next){
//             temp=temp->next;
//         }
//         temp->next=new_node;
//         return;
//     }
// };
// linked_list graph[MAX_INT];
// bool visited[MAX_INT]={0};
// void add_edge(int src,int des,bool bi_direc=true){
//     graph[src].push_back(des);
//     if(bi_direc)graph[des].push_back(src);
// }
// void dfs(int src){
//     cout<<src<<" ";
//     visited[src]=true;
//     node* neighbhour=graph[src].head;
//     while(neighbhour){
//         if(!visited[neighbhour->val]){
//             dfs(neighbhour->val);
//         }
//         neighbhour=neighbhour->next;
//     }
// }
// int connected_comp(int v){
//     int result=0;
//     for(int i=0;i<v;i++){
//         if(!visited[i]){
//             result++;
//             dfs(i);
//         }
//         cout<<endl;
//     }
//     return result;
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     while(e--){
//         int src,des;
//         cin>>src>>des;
//         add_edge(src,des);
//     }
// cout<<connected_comp(v);
// return 0;
// }

// 3.No. of Provinces
// #include <bits/stdc++.h>
// using namespace std;
// void dfs(vector<int> graph[],vector<int>&visited,int node){
//     visited[node]=1;
//     for(auto i:graph[node]){
//         if(!visited[i]){
//             dfs(graph,visited,i);
//         }
//     }
// }
// int no_of_provinces(vector<int>graph[],vector<int> &visited,int v){
//     int cnt=0;
//     for(int crnt_node=1;crnt_node<=v;crnt_node++){
//         if(!visited[crnt_node]){
//             cnt++;
//             dfs(graph,visited,crnt_node);
//         }
//     }
//     return cnt;
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     vector<int> graph[v+1];
//     while(e--){
//         int src,des;
//         cin>>src>>des;
//         graph[src].push_back(des);
//         graph[des].push_back(src);
//     }
//     vector<int> visited(v,0);
//     cout<<no_of_provinces(graph,visited,v);
// return 0;
// }


