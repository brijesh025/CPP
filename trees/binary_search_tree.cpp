// 1.INSERTION
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
// class binary_search_tree{
//     public:
//     node* root;
//     binary_search_tree(){
//         root=nullptr;
//     }
//     void insert(int data){
//     node* new_node=new node(data);
//     if(root==nullptr){
//         root=new_node;
//         return;
//     }
//     node* crnt=root;
//     while(true){
//         if(crnt->val>data){
//             if(crnt->left==nullptr){
//                 crnt->left=new_node;
//                 return;
//             }
//             crnt=crnt->left;
//         }else{
//             if(crnt->right==nullptr){
//                 crnt->right=new_node;
//                 return;
//             }
//             crnt=crnt->right;
//         }
//     }
// }     
// };
// node* recursive_insert(node* root,int data){
//         if(root==nullptr){
//             node* new_node=new node(data);
//             return new_node;
//         }
//         if(root->val>data) root->left=recursive_insert(root->left,data);
//         else root->right=recursive_insert(root->right,data);
//     }
// void in_order(node* root){ //tc->o(n)
//     if(root==nullptr)return;
//     in_order(root->left);
//     cout<<root->val<<" ";
//     in_order(root->right);
// }
// int main(){
//     binary_search_tree b;
//     b.root=recursive_insert(b.root,4);
//     recursive_insert(b.root,1);
//     recursive_insert(b.root,3);
//     recursive_insert(b.root,2);
//     recursive_insert(b.root,6);
//     recursive_insert(b.root,15);
//     recursive_insert(b.root,5);
//     in_order(b.root);
// }

// 2.SEARCH AND DELETION

// A.GENERAL DELETION
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
// class binary_search_tree{
//     public:
//     node* root;
//     binary_search_tree(){
//         root=nullptr;
//     }
//     void insert(int data){
//     node* new_node=new node(data);
//     if(root==nullptr){
//         root=new_node;
//         return;
//     }
//     node* crnt=root;
//     while(true){
//         if(crnt->val>data){
//             if(crnt->left==nullptr){
//                 crnt->left=new_node;
//                 return;
//             }
//             crnt=crnt->left;
//         }else{
//             if(crnt->right==nullptr){
//                 crnt->right=new_node;
//                 return;
//             }
//             crnt=crnt->right;
//         }
//     }
// }
// bool search(int data){
//     if(root==nullptr) return false;
//     node* temp=root;
//     while(temp){
//         if(temp->val==data) return true; 
//         if(temp->val<data) temp=temp->right;
//         else temp=temp->left;
//     }
// }
// };
// void in_order(node* root){
//     if(root==nullptr) return;
//     in_order(root->left);
//     cout<<root->val<<" ";
//     in_order(root->right);
// }
// bool rec_search(node* root,int data){
//     if(root==nullptr)return false;
//     else if(root->val==data) return true;
//     else if(root->val<data) rec_search(root->right,data); 
//     else rec_search(root->left,data); 
// }     
// node* delete_ele(node* root,int data){
//     if(root==nullptr) return root;
//     if(root->val<data) root->right=delete_ele(root->right,data);
//     else if(root->val > data) root->left=delete_ele(root->left,data);
//     else{
//         if(!root->left and !root->right){
//             free(root);
//             return nullptr;
//         }
//         else if(!root->left){
//             node* temp=root->right;
//             free(root);
//             return temp;
//         }
//         else if(!root->right){
//             node* temp=root->left;
//             free(root);
//             return temp;
//         }
//         else{
//             node* temp = root->left;
//             while(temp->right) temp = temp->right;
//             root->val = temp->val;
//             root->left = delete_ele(root->left, temp->val); // Recursively delete the just smaller node
//         }
//     }
//     return root;
// }
// int main(){
// binary_search_tree b;
// b.insert(8);
// b.insert(1);
// b.insert(6);
// b.insert(3);
// b.insert(17);
// b.insert(4);
// b.insert(12);
// b.insert(11);
// b.insert(15);
// b.insert(9);
// in_order(b.root);
// delete_ele(b.root,12);
// // cout<<b.search(40);
// // cout<<rec_search(b.root,9);
// cout<<endl;
// in_order(b.root);
// }

// B.TRANSPLANT DELETION
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node* parent;
//     node(int data){
//         val=data;
//         left=right=parent=nullptr;
//     }
// };
// class bst{
//     public:
//     node* root;
//     bst(){
//         root=nullptr;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val<data){
//                 if(temp->right==nullptr){
//                     new_node->parent=temp;
//                     temp->right=new_node;
//                     return;
//                 } 
//                 temp=temp->right;
//             }
//             if(temp->val>data){
//                 if(temp->left==nullptr){
//                     new_node->parent=temp;
//                     temp->left=new_node;
//                     return;
//                 } 
//                 temp=temp->left;
//             }
//         }
//     }
// };
// bool is_bst(node* root,node* &pre){
//     if(root==nullptr) return true;
//     if(!is_bst(root->left,pre)) return false;
//     if(pre and pre->val>=root->val) return false;
//     pre=root;
//     if(!is_bst(root->right,pre)) return false;
//     return true;
//     }
// node* search_bst(node* root,int data){
//     if(root==nullptr) return nullptr;
//     if(data<root->val) return search_bst(root->left,data);
//     else if(data>root->val) return search_bst(root->right,data);
//     else return root;
// }
// node* transplant(node* root, node* u, node* v) {
//     if (u->parent == nullptr) {
//         root = v;
//     } else if (u == u->parent->left) {
//         u->parent->left = v;
//     } else {
//         u->parent->right = v;
//     }
//     if (v != nullptr) {
//         v->parent = u->parent;
//     }
//     return root;
// }
// node* minimum(node* x) {
//     while (x->left != nullptr) {
//         x = x->left;
//     }
//     return x;
// }
// node* delete_bst(node* root, int data) {
//     node* target = search_bst(root, data);
//     if (target == nullptr) return root; // Node not found
//     if (target->left == nullptr) {
//         root = transplant(root, target, target->right);
//     } else if (target->right == nullptr) {
//         root = transplant(root, target, target->left);
//     } else {
//         node* y = minimum(target->right); // Successor
//         if (y->parent != target) {
//             root = transplant(root, y, y->right);
//         }
//         root = transplant(root, target, y);
//         y->right = target->right;
//         y->right->parent = y;
//         y->left = target->left;
//         y->left->parent = y;
//     }
//     delete target; // Free the memory of the deleted node
//     return root;
// }
// void in_order(node* root){
//     if(root==nullptr) return;
//     in_order(root->left);
//     cout<<root->val<<"("<<root->parent<<")"<<" ";
//     in_order(root->right);
// }
// int main(){
//     bst b;
// b.insert(4);
// b.insert(2);
// b.insert(1);
// b.insert(3);
// b.insert(6);
// b.insert(5);
// b.insert(8);
// b.insert(7);
// b.insert(9);
//     in_order(b.root);
//     cout<<endl;
//     delete_bst(b.root,6);
//     in_order(b.root);
//     return 0;
// }
// 3.SORTED ARRAY TO BALANCED BST---TC->O(n) and SC-->O(log(n))
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
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val<data){
//                 if(temp->right==nullptr){
//                     temp->right=new_node;
//                     return;
//                 } 
//                 temp=temp->right;
//             }
//             if(temp->val>data){
//                 if(temp->left==nullptr){
//                     temp->left=new_node;
//                     return;
//                 } 
//                 temp=temp->left;
//             }
//         }
//     }
// };
// node* arr_to_bst(vector <int> arr,int l,int r){
//     if(l>r)return nullptr;
//     int mid= (l+r)/2;
//     node* root=new node(arr[mid]);
//     root->left=arr_to_bst(arr,l,mid-1);
//     root->right=arr_to_bst(arr,mid+1,r);
//     return root;
// }
// void pre_order(node* root){
//     if(root==nullptr) return;
//     cout<<root->val<<" ";
//     pre_order(root->left);
//     pre_order(root->right);
// }
// int main(){
// binary_tree balanced_bst;
// int size;
// cin>>size;
// vector<int> v(size);
// for(int &i:v)cin>>i;
// balanced_bst.root=arr_to_bst(v,0,size-1);
// pre_order(balanced_bst.root);
// return 0;
// }

// 4.LOWEST COMMON ANCESSTOR AND DELETE LEAF NODES
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
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val<data){
//                 if(temp->right==nullptr){
//                     temp->right=new_node;
//                     return;
//                 } 
//                 temp=temp->right;
//             }
//             if(temp->val>data){
//                 if(temp->left==nullptr){
//                     temp->left=new_node;
//                     return;
//                 } 
//                 temp=temp->left;
//             }
//         }
//     }
// };
// void pre_order(node* root){
//     if(root==nullptr) return;
//     cout<<root->val<<" ";
//     pre_order(root->left);
//     pre_order(root->right);
// }
// node* common_ancs(node* root,int data1,int data2){ //data1<data2 and they are present in BST
//     if(root==nullptr) return nullptr;
//     else if(root->val>data2){
//         return common_ancs(root->left,data1,data2);
//     }
//     else if(root->val<data1){
//         return common_ancs(root->right,data1,data2);
//     }
//     else return root;
// }
// node* del_leaf(node* root){
//     if(root==nullptr) return nullptr;
//     else if(!root->left and !root->right){
//         free(root);
//         return nullptr;
//     }
//     root->left=del_leaf(root->left);
//     root->right=del_leaf(root->right);
//     return root;
// }
// int main(){
// binary_tree b;
// b.insert(4);
// b.insert(2);
// b.insert(6);
// b.insert(1);
// b.insert(3);
// b.insert(5);
// b.insert(7);
// pre_order(b.root);
// cout<<endl;
// // cout<<common_ancs(b.root,3,6)->val;
// del_leaf(b.root);
// pre_order(b.root);
// return 0;
// }

// 5.INORDER PREDECSSOR AND SUCCESSOR---->TC->O(log(n)) SC->O(log(n))
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
//     public:
//     node* root;
//     binary_tree(){
//         root=nullptr;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val<data){
//                 if(!temp->right){
//                     temp->right=new_node;
//                     return;
//                 }
//                 temp=temp->right;
//             }
//             else{
//                 if(!temp->left){
//                     temp->left=new_node;
//                     return;
//                 }
//                 temp=temp->left;
//             }
//         }
//     }
// };
// void in_order(node* root){
//     if(root==nullptr) return;
//     in_order(root->left);
//     cout<<root->val<<" ";
//     in_order(root->right);
// }
// void in_order_pred_succ(node* root,int data,node* &pre,node* &suc){
//     if(root==nullptr) return;
//     if(root->val==data){
//         if(root->left){
//         node* temp=root->left;
//         while(temp->right)temp=temp->right;
//         pre=temp;
//     }
//     if(root->right){
//         node* temp=root->right;
//         while(temp->left) temp=temp->left;
//         suc=temp;
//     }
//     return;
//     }
//     if(root->val>data){
//         suc=root;
//         in_order_pred_succ(root->left,data,pre,suc);
//         }
//     else if(root->val<data){
//         pre=root;
//         in_order_pred_succ(root->right,data,pre,suc);
//         }
// }
// int main(){
// binary_tree b;
// b.insert(4);
// b.insert(2);
// b.insert(6);
// b.insert(1);
// b.insert(3);
// b.insert(5);
// b.insert(7);
// in_order(b.root);
// cout<<endl;
// node* pre=nullptr;
// node* suc=nullptr;
// in_order_pred_succ(b.root,3,pre,suc);
// cout<<pre->val<<" "<<suc->val;
// return 0;
// }

// 6.CHECK WHETHER A BST OR NOT
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
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val<data){
//                 if(temp->right==nullptr){
//                     temp->right=new_node;
//                     return;
//                 } 
//                 temp=temp->right;
//             }
//             if(temp->val>data){
//                 if(temp->left==nullptr){
//                     temp->left=new_node;
//                     return;
//                 } 
//                 temp=temp->left;
//             }
//         }
//     }
// };
// void pre_order(node* root){
//     if(root==nullptr) return;
//     cout<<root->val<<" ";
//     pre_order(root->left);
//     pre_order(root->right);
// }
// bool is_validBST(node* root,node* &pre){
//     if(root==nullptr) return true;
//     is_validBST(root->left,pre);
//     if(pre!= nullptr and pre->val>=root->val)return false;
//     pre=root;
//     is_validBST(root->right,pre);
// }
// int main(){
// binary_tree b;
// b.root=new node(8);
// b.insert(4);
// b.insert(5);
// b.insert(6);
// b.root->left->left=new node(20);
// b.insert(7);
// b.insert(12);
// b.insert(13);
// b.insert(9);
// pre_order(b.root);
// cout<<endl;
// // is_bst(b.root);
// node* pre=nullptr;
// cout<<is_validBST(b.root,pre);
// return 0;
// }

// 7.IDENTICAL OR NOT
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* right;
//     node* left;
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
//     void insert(int data){
//         node* new_node=new node(data);
//         if(root==nullptr){
//             root=new_node;
//             return;
//         }
//         node* temp=root;
//         while(temp){
//             if(temp->val>data){
//                 if(!temp->left){
//                 temp->left=new_node;
//                 return;
//                 }
//                 temp=temp->left;
//             }
//             else{
//                 if(!temp->right){
//                     temp->right=new_node;
//                     return;
//                 }
//                 temp=temp->right;
//             }
//         }
//     }
// };
// bool chk_identical(vector<int> v1,vector<int> v2,int m,int n,int minm,int maxm){
//     int i;
//     for(i=m;i<v1.size();i++){
//         if(v1[i]<maxm and v1[i]>minm) break;
//     }
//     int j;
//     for(j=m;j<v1.size();j++){
//         if(v2[j]<maxm and v2[j]>minm) break;
//     }
//     if(i==v1.size() and j==v2.size())return true;
//     else if((i==v1.size() and j!=v2.size()) or (i!=v1.size() and j==v2.size())) return false;
//     else if(v1[i]!=v2[j]) return false;
//     return chk_identical(v1,v2,m+1,n+1,minm,v1[i]) and chk_identical(v1,v2,m+1,n+1,v1[i],maxm);
// }
// int main(){
//     int size;
//     cin>>size;
// vector<int>v1(size);
// vector<int>v2(size);
// for(int &i:v1) cin>>i;
// for(int &i:v2) cin>>i;
// cout<<chk_identical(v1,v2,0,0,INT16_MIN,INT16_MAX);
// return 0;
// }

// 8.PREORDER ARRAY TO BST
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* right;
//     node* left;
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
// };
// node* bstFromPreorderHelper(vector<int> &preorder,int &idx,int up_bnd){
//     if(idx>=preorder.size()) return nullptr;
//     if(preorder[idx]>=up_bnd)return nullptr;
//     node* root=new node(preorder[idx]);
//     idx++;
//     root->left=bstFromPreorderHelper(preorder,idx,root->val);
//     root->right=bstFromPreorderHelper(preorder,idx,up_bnd);
//     return root;
// }
// node* bstFromPreorder(vector <int> &preorder){
//     int idx=0;
//     return bstFromPreorderHelper(preorder,idx,INT_MAX);
// }
// void in_order(node* root){
//     if(root==nullptr) return;
//     in_order(root->left);
//     cout<<root->val<<" ";
//     in_order(root->right);
// }
// int main(){
//     int size;
//     cin>>size;
// vector<int> v(size);
// for(int&i:v) cin>>i;
// binary_tree b;
// b.root=bstFromPreorder(v);
// in_order(b.root);
// return 0;
// }

// 9.MAXM SUM BST SUBTREE FROM A BINARY TREE 
// #include <iostream>
// using namespace std;
// class node {
// public:
//     int val;
//     node* left;
//     node* right;
//     node(int data) : val(data), left(nullptr), right(nullptr) {}
// };
// class bst {
// public:
//     node* root;
//     bst() : root(nullptr) {}
// };
// node* insert(node* root, int data) {
//     if (root == nullptr) return new node(data);
//     else if (data < root->val) root->left = insert(root->left, data);
//     else root->right = insert(root->right, data);
//     return root;
// }
// bool is_bst(node* root, node*& pre) {
//     if (root == nullptr) return true;
//     is_bst(root->left, pre);
//     if (pre != nullptr && pre->val >= root->val) return false;
//     pre = root;
//     is_bst(root->right, pre);
// }
// int sum(node* root) {
//     if (root == nullptr) return 0;
//     return sum(root->left) + root->val + sum(root->right);
// }
// node* find_max_bst(node* root, int& crnt_sum, node*& crnt_node) {
//     if (root == nullptr) return crnt_node;
//     find_max_bst(root->left, crnt_sum, crnt_node);
//     node* pre = nullptr;
//     if (is_bst(root, pre)) {
//         int root_sum = sum(root);
//         if (root_sum > crnt_sum) {
//             crnt_sum = root_sum;
//             crnt_node = root;
//         }
//     }
//     find_max_bst(root->right, crnt_sum, crnt_node);
//     return crnt_node;
// }
// void inorder(node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }
// int main() {
//     bst b;
//     b.root = insert(b.root, 8);
//     insert(b.root, 4);
//     insert(b.root, 5);
//     b.root->left->left=new node(70);
//     insert(b.root, 6);
//     insert(b.root, 7);
//     insert(b.root, 12);
//     insert(b.root, 13);
//     insert(b.root, 9);
//     cout << "Inorder of the whole tree: ";
//     inorder(b.root);
//     cout << endl;
//     int max_sum = 0;
//     node* max_bst_node = nullptr;
//     find_max_bst(b.root, max_sum, max_bst_node);
//     cout << "Inorder of the max BST subtree: ";
//     inorder(max_bst_node);
//     cout << endl;
//     return 0;
// }
