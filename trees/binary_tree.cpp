// 1.IMPLEMENTATION OF BINARY TREE
// #include <bits/stdc++.h>
// using namespace std;
//class node{
//         public:
//         int val;
//         node* left;
//         node* right;
//         node(int data){
//             val=data;
//             left=right=nullptr;
//         }
//     };
// class binary_tree{
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.r_insert(3);
// cout<<b.root->val<<endl;
// cout<<b.root->left->val<<endl;
// cout<<b.root->right->val<<endl;
// return 0;
// }

// 2.TRAVERSAL

// A.DFS
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//         public:
//         int val;
//         node* left;
//         node* right;
//         node(int data){
//             val=data;
//             left=right=nullptr;
//         }
//     };
// class binary_tree{
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// void pre_order(node* root_node){
//     if(root_node==nullptr) return;
//     cout<<root_node->val<<endl;
//     pre_order(root_node->left);
//     pre_order(root_node->right);
// }
// void in_order(node* root_node){
//     if(root_node==nullptr) return;
//     in_order(root_node->left);
//     cout<<root_node->val<<endl;
//     in_order(root_node->right);
// }
// void post_order(node* root_node){
//     if(root_node==nullptr) return;
//     post_order(root_node->left);
//     post_order(root_node->right);
//     cout<<root_node->val<<endl;
// }
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.root->left->right=new node(10);
// b.r_insert(3);
// b.root->left->right->left=new node(40);
// b.root->left->right->right=new node(80);
// b.l_insert(4);
// b.l_insert(5);
// b.l_insert(6);
// b.r_insert(7);
// cout<<"preoder:"<<endl;
// pre_order(b.root);
// cout<<"inorder:"<<endl;
// in_order(b.root);
// cout<<"postorder:"<<endl;
// post_order(b.root);
// return 0;
// }

// B.BFS

// 1.LEVEL ORDER
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//         public:
//         int val;
//         node* left;
//         node* right;
//         node(){
//             left=right=nullptr;
//             val=0;
//         }
//         node(int data){
//             val=data;
//             left=right=nullptr;
//         }
//     };
// class que{
//     node* arr[INT16_MAX];
//     int front;
//     int rear;
//     public:
//     que(){
//         front=-1;
//         rear=-1;
//     }
//     bool is_empty(){
//         return front==-1;
//     }
//     bool is_full(){
//         return (rear-front)==INT16_MAX-1;
//     }
//     node* front_ele(){
//         if(is_empty()) return nullptr;
//         return arr[front];
//     }
//     int size(){
//         return rear-front+1;
//     }
//     void enque(node* data){
//         if(is_full()) return;
//         else if(is_empty()){
//             arr[++front]=data;
//             ++rear;
//             return;
//         }
//         arr[++rear]=data;
//     }
//     void deque(){
//         if(is_empty()) return;
//         front++;
//         if(front>rear) front=rear=-1;
//     }
// };
// class binary_tree{
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// void level_order(node* root_node){
//     if(root_node==nullptr) return;
//     que q;
//     q.enque(root_node);
//     while(!q.is_empty()){
//         int crnt_level_nodes=q.size();
//         while (crnt_level_nodes--)
//         {
//             node* crnt_node=q.front_ele();
//             q.deque();
//             cout<<crnt_node->val<<" ";
//             if(crnt_node->left) q.enque(crnt_node->left);
//             if(crnt_node->right) q.enque(crnt_node->right);
//         }
//         cout<<endl;      
//     }
// }
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.root->left->right=new node(10);
// b.r_insert(3);
// b.root->left->right->left=new node(40);
// b.root->left->right->right=new node(80);
// b.l_insert(4);
// b.l_insert(5);
// b.l_insert(6);
// b.r_insert(7);
// level_order(b.root);
// return 0;
// }

//2.REVERSE LEVEL ORDER
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int data){
//         val=data;
//         right=left=nullptr;
//     }
// };
// class stacks{
//     node* arr[INT16_MAX];
//     int top;
//     public:
//     stacks(){
//         top=-1;
//     }
//     bool empty(){
//         return top==-1;
//     }
//     bool full(){
//         return top==INT16_MAX-1;
//     }
//     node* peek(){
//         if(empty()) return nullptr;
//         return arr[top];
//     }
//     void push(node* data){
//         if(full())  return;
//         arr[++top]=data;
//     }
//     void pop(){
//         if(empty()) return;
//         top--;
//     }
//     int size(){
//         return top;
//     }
// };
// class binary_tree{
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// void reverse_level_order(node* root){
//     stacks s;
//     queue<node*> q;
//     q.push(root);
//     while(!q.empty()){
//         node* crnt_node=q.front();
//         q.pop();
//         s.push(crnt_node);
//         if(crnt_node->right)q.push(crnt_node->right);
//         if(crnt_node->left)q.push(crnt_node->left);
//     }
//     while(!s.empty()){
//         cout<<s.peek()->val<<" ";
//         s.pop();
//     }
// }
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.root->left->right=new node(15);
// b.root->left->right->left=new node(45);
// b.l_insert(8);
// b.root->left->left->right=new node(16);
// b.l_insert(17);
// b.r_insert(3);
// b.root->left->left->right=new node(49);
// b.r_insert(4);
// b.r_insert(5);
// b.root->right->right->right->left=new node(48);
// b.root->right->right->right->left->left=new node(23);
// b.root->right->right->right->left->left->right=new node(23);
// b.r_insert(6);
// reverse_level_order(b.root);
// return 0;
// }

// 3.ZIG ZAG TRAVERAL
// #include<bits/stdc++.h>
// using namespace  std;
// class node {
// public:
//     int val;
//     node* left;
//     node* right;
//     node(int data) : val(data), left(nullptr), right(nullptr) {}
// };
// class BST {
// public:
//     node* root;
//     BST() : root(nullptr) {}
// };
// void inOrder(node* node) {
//         if (node == nullptr) return;
//         inOrder(node->left);
//         std::cout << node->val << " ";
//         inOrder(node->right);
//     }
// node* insert(node* root, int data) {
//         if (root == nullptr) {
//             return new node(data);
//         } else if (data < root->val) {
//             root->left = insert(root->left, data);
//         } else if (data > root->val) {
//             root->right = insert(root->right, data);
//         }
//         return root;
//     }
// void ziz_zag(node* root){
// stack <node*> crnt_level;
// stack <node*> next_level;
// bool l_to_r=true;
//     crnt_level.push(root);
//     while(!crnt_level.empty()){
//        node* crnt=crnt_level.top();
//        crnt_level.pop();
//        cout<<crnt->val<<" ";
//        if(l_to_r){
//         if(crnt->left)next_level.push(crnt->left);
//         if(crnt->right)next_level.push(crnt->right);
//        }
//        else {
//         if(crnt->right)next_level.push(crnt->right);
//         if(crnt->left)next_level.push(crnt->left);
//        }
//        if(crnt_level.empty()){
//         swap(crnt_level,next_level);
//         l_to_r=!l_to_r;
//         cout<<endl;
//        }
//     }
// }
// int main(){
//     BST b;
//     b.root=new node(8);
//     insert(b.root,12);
//     insert(b.root,11);
//     insert(b.root,10);
//     insert(b.root,14);
//     insert(b.root,5);
//     insert(b.root,6);
//     insert(b.root,4);
//     insert(b.root,3);
//     insert(b.root,2);
//     insert(b.root,1);
//     insert(b.root,9);
//     insert(b.root,18);
//     inOrder(b.root);
//     cout<<endl;
//     ziz_zag(b.root);
// }

// 4.DEPTH OF A TREE
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int data){
//         val=data;
//         left=right=nullptr;
//     }
// };
// class binary_tree{
// public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// int depth(node* root){
//     if(root==nullptr) return 0;
//    int l_depth=depth(root->left);
//    int r_depth=depth(root->right);
//    return max(l_depth,r_depth)+1;
// }
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.root->left->right=new node(15);
// b.root->left->right->left=new node(45);
// b.l_insert(8);
// b.root->left->left->right=new node(16);
// b.l_insert(17);
// b.r_insert(3);
// b.root->left->left->right=new node(49);
// b.r_insert(4);
// b.r_insert(5);
// b.root->right->right->right->left=new node(48);
// b.root->right->right->right->left->left=new node(23);
// b.root->right->right->right->left->left->right=new node(23);
// b.r_insert(6);
// cout<<depth(b.root);
// return 0;
// }

// 4.NO. OF LEAF NODES AND TREE VIEW
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int data){
//         val=data;
//         right=left=nullptr;
//     }
// };
// class binary_tree{
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void l_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->left=new_node;
//         tail=tail->left;
//     }
//     void r_insert(int data){
//         node* new_node=new node(data);
//         static node* tail=root;
//         if(root==nullptr){
//             root=new_node;
//             tail=root;
//             return;
//         }
//         tail->right=new_node;
//         tail=tail->right;
//     }
// };
// int cnt_leaf_node(node* root){
//     if(root==nullptr) return 0;
//     if(root->left==nullptr and root->right==nullptr)return 1;
//     return cnt_leaf_node(root->left)+cnt_leaf_node(root->right);
// }
// int right_most_view(node* root){
//     queue<node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int crnt_nodes=q.size();
//         while(crnt_nodes){
//         node* crnt_node=q.front();
//         q.pop();
//         if(crnt_nodes==1) cout<<crnt_node->val<<" ";
//         if(crnt_node->left)q.push(crnt_node->left);
//         if(crnt_node->right)q.push(crnt_node->right);
//         crnt_nodes--;
//         }
//     }
// }
// vector<int> top_most_view(node* root){
//     vector<int> ans;
//     if(root==nullptr) return ans;
//     map<int,int> m;
//     queue<pair<node*,int>> q;
//     q.push(make_pair(root,0));
//     while(!q.empty()){
//         int crnt_nodes=q.size();
//         while(crnt_nodes--){
//             pair<node*,int> p=q.front();
//             node* crnt_node=p.first;
//             int crnt_clmn=p.second;
//             q.pop();
//             if(m.find(crnt_clmn)==m.end()){
//                 m[crnt_clmn]=crnt_node->val;
//             }
//             if(crnt_node->left) q.push(make_pair(crnt_node->left,crnt_clmn-1));
//             if(crnt_node->right) q.push(make_pair(crnt_node->right,crnt_clmn+1));
//         }
//     }
//         for(auto i:m)
//             ans.push_back(i.second);
//         return ans;
// }
// vector<int> bottom_most_view(node* root){
//     vector<int> ans;
//     if(root==nullptr) return ans;
//     map<int,int> m;
//     queue<pair<node*,int>> q;
//     q.push(make_pair(root,0));
//     while(!q.empty()){
//         int crnt_nodes=q.size();
//         while(crnt_nodes--){
//             pair<node*,int> p=q.front();
//             node* crnt_node=p.first;
//             int crnt_clmn=p.second;
//             q.pop();
//             m[crnt_clmn]=crnt_node->val;
//             if(crnt_node->left) q.push(make_pair(crnt_node->left,crnt_clmn-1));
//             if(crnt_node->right) q.push(make_pair(crnt_node->right,crnt_clmn+1));
//         }
//     }
//         for(auto i:m)
//             ans.push_back(i.second);
//         return ans;
// }
// int main(){
// binary_tree b;
// b.l_insert(1);
// b.l_insert(2);
// b.root->left->right=new node(15);
// b.root->left->right->left=new node(45);
// b.l_insert(8);
// b.root->left->left->right=new node(16);
// b.l_insert(17);
// b.r_insert(3);
// b.root->left->left->right=new node(49);
// b.r_insert(4);
// b.r_insert(5);
// b.root->right->right->right->left=new node(48);
// b.root->right->right->right->left->left=new node(23);
// b.root->right->right->right->left->left->right=new node(23);
// b.r_insert(6);
// cout<<cnt_leaf_node(b.root);
// // right_most_view(b.root);
// // vector<int>top_ans=top_most_view(b.root);
// // vector<int>bottom_ans=bottom_most_view(b.root);
// // for(int &i:bottom_ans) cout<<i<<" ";
// return 0;
// }

