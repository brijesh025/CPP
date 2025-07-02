// 1.CHECK NODE==RIGHT+LEFT
// #include <iostream>
// using namespace  std;
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int data) : val(data), left(nullptr), right(nullptr) {}
// };
// class BST {
// public:
//     Node* root;
//     BST() : root(nullptr) {}
//     Node* insert(Node* root, int data) {
//         if (root == nullptr) {
//             return new Node(data);
//         } else if (data < root->val) {
//             root->left = insert(root->left, data);
//         } else if (data > root->val) {
//             root->right = insert(root->right, data);
//         }
//         return root;
//     }
//     void inOrder(Node* node) {
//         if (node == nullptr) return;
//         inOrder(node->left);
//         std::cout << node->val << " ";
//         inOrder(node->right);
//     }
// };
// int sum(Node* node) {
//         if (node == nullptr) return 0;
//         return sum(node->left) + node->val + sum(node->right);
//     }
// bool checkSumProperty(Node* node) {
//         if (node == nullptr) return true;
//         if(!node->left and !node->right) return true;
//         int leftSum = sum(node->left);
//         int rightSum = sum(node->right);
//         bool crnt_chk= node->val == leftSum + rightSum;
//         return crnt_chk && checkSumProperty(node->left) && checkSumProperty(node->right);
//     }
// int main() {
//     BST b;
//     b.root = new Node(14);
//     b.root->left = new Node(2);
//     b.root->left->left = new Node(1);
//     b.root->left->right = new Node(1);
//     b.root->right = new Node(5);
//     b.root->right->left = new Node(3);
//     b.root->right->right = new Node(2);
//     b.inOrder(b.root);
//     std::cout << "\nSum: " << sum(b.root) << "\n";
//     std::cout << "Check Sum Property: " << (checkSumProperty(b.root) ? "Yes" : "No") << "\n";
//     return 0;

