// A.WITH STL
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[], vector<int>& visited, int node) {// tc->O(V+E)
    visited[node] = 1;
    cout << node << " ";
    for (auto nbr : graph[node]) {
        if (!visited[nbr]) {
            dfs(graph, visited, nbr);
        }
    }
}
void bfs(vector<int> graph[],vector<int>&visited,int node){ //tc->O(V+E)
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int cnrt_level=q.size();
        while(cnrt_level--){
            node=q.front(); 
            q.pop();
            cout<<node<<" ";
            for(auto i:graph[node]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
        }
        }
        cout<<endl;
    }
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<int> graph[v+1];
    for(int i=0;i<e;i++) {
        int src, des;
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    vector<int> visited(v+1, 0);
    int start_node = 0;
    // dfs(graph, visited, start_node);
    bfs(graph,visited,start_node);
    return 0;
}

// B.WITHOUT STL

// i.Adjency list
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
// set <int> visited;//instead use: bool visited[INT_MAX];
// queue <int> q;
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
// void dfs(int crnt,int end){
//     cout<<crnt<<" ";
//     visited.insert(crnt);
//     if(crnt==end) return;
//     node* temp=graph[crnt].head;
//     while(temp){
//         if(!visited.count(temp->val)){
//         dfs(temp->val,end);
//         }
//         temp=temp->next;
//     }
//     return;
// }
// void bfs(int crnt){
//     q.push(crnt);
//     visited.insert(crnt);
//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         node* temp=graph[q.front()].head;
//         while(temp){
//             if(!visited.count(temp->val)){
//                 q.push(temp->val);
//                 visited.insert(temp->val);
//             }
//             temp=temp->next;
//         }
//         q.pop();
//     }
// }
// int main(){
//     int v,e;
//     cin>>v>>e;
//     while(e--){
//         int src,des;
//         cin>>src>>des;
//         add_edge(src,des);
//     }
//     display(7);
//     // dfs(0,2);
//     bfs(0);
// return 0;
// }

// ii.Adjency Map
// #include <iostream>
// using namespace std;
// #define MAX 100  // Maximum number of vertices in the graph
// class Stack {
// private:
//     int items[MAX];
//     int top;
// public:
//     Stack() : top(-1) {}
//     void push(int item) {
//         if (top >= MAX - 1) {
//             std::cout << "Stack overflow\n";
//             return;
//         }
//         items[++top] = item;
//     }
//     int pop() {
//         if (top == -1) {
//             std::cout << "Stack underflow\n";
//             return -1;
//         }
//         return items[top--];
//     }
//     bool isEmpty() {
//         return top == -1;
//     }
// };
// class Queue {
// private:
//     int items[MAX];
//     int front, rear;
// public:
//     Queue() : front(0), rear(-1) {}
//     void enqueue(int item) {
//         if (rear >= MAX - 1) {
//             std::cout << "Queue overflow\n";
//             return;
//         }
//         items[++rear] = item;
//     }
//     int dequeue() {
//         if (front > rear) {
//             std::cout << "Queue underflow\n";
//             return -1;
//         }
//         return items[front++];
//     }
//     bool isEmpty() {
//         return front > rear;
//     }
// };
// int adj[MAX][MAX];
// int visited[MAX];
// int n;
// void initializeGraph() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             adj[i][j] = 0;
//         }
//         visited[i] = 0;
//     }
// }
// void DFS(int start) {
//     Stack stack;
//     stack.push(start);
//     visited[start] = 1;
//     while (!stack.isEmpty()) {
//         int v = stack.pop();
//         std::cout << v << " ";
//         for (int i = n - 1; i >= 0; i--) {
//             if (adj[v][i] == 1 && !visited[i]) {
//                 stack.push(i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }
// void BFS(int start) {
//     Queue queue;
//     queue.enqueue(start);
//     visited[start] = 1;
//     while (!queue.isEmpty()) {
//         int v = queue.dequeue();
//         std::cout << v << " ";
//         for (int i = 0; i < n; i++) {
//             if (adj[v][i] == 1 && !visited[i]) {
//                 queue.enqueue(i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }
// int main() {
//     n = 5;  // Example: Graph with 5 vertices
//     initializeGraph();
//     adj[0][1] = adj[1][0] = 1;
//     adj[0][2] = adj[2][0] = 1;
//     adj[1][3] = adj[3][1] = 1;
//     adj[2][4] = adj[4][2] = 1;
//     std::cout << "DFS Traversal: ";
//     DFS(0);
//     std::cout << "\n";
//     for (int i = 0; i < n; i++) {
//         visited[i] = 0;
//     }
//     std::cout << "BFS Traversal: ";
//     BFS(0);
//     std::cout << "\n";
//     return 0;
// }