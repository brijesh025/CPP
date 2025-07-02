// 1.Reverse element of que
// #include <bits/stdc++.h>
// #include <stack>
// using namespace std;
// class node{
// public:
//     int val;
//     node* next;
//     node(int data){
//         val=data;
//         next=NULL;
//     }
// };
// class queues{
//     node* Front;
//     node* back;
//     int capacity;
//     int size;
// public:
// queues(int c){
//         Front=NULL;
//         back=NULL;
//         capacity=c;
//         size=0;
//     }
// bool isEmpty(){
//     return Front==NULL;
// }
// bool isFull(){
//     return size==capacity;
// }
// int front(){
//     return Front->val;
// }
// void enque(int data){
//     node* new_node=new node(data);
//     if(Front==NULL){
//         back=new_node;
//         Front=new_node;
//         size++;
//         return;
//     }
//     back->next=new_node;
//     back=back->next;
//     size++;
// }
// void deque(){
//     if(Front==back){
//         Front=NULL;
//         back=NULL;
//         size--;
//         return;
//     }
//     node* temp=Front;
//     Front=Front->next;
//     free(temp);
//     size--;
// }
// void rev(){
// }
// };
// int main(){
// queues q(5);
// q.enque(1);
// q.enque(2);
// q.enque(3);
// q.enque(4);
// q.enque(5);
// stack<int> s;
// while(!q.isEmpty()){
//     s.push(q.front());
//     q.deque();
// }
// while(!s.empty()){
//     q.enque(s.top());
//     s.pop();
// }
// while(!q.isEmpty()){
//     cout<<q.front()<<" ";
//     q.deque();
// }
// return 0;
// }

// 2.SLIDING WINDOW MAXIMUM  
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque <int> hol_ind;
//     vector <int> result;
//     for(int i=0;i<nums.size();i++){
//         while(!hol_ind.empty() and nums[hol_ind.back()]<nums[i]){
//             hol_ind.pop_back();
//         }
//         hol_ind.push_back(i);
//         if(i-hol_ind.front()==k) hol_ind.pop_front();
//         if(i>=k-1){
//             result.push_back(nums[hol_ind.front()]);
//         }
//     }
//     return result;     
//     }
// int main(){
//     int k=3;
//     vector <int> nums={1,3,-1,-3,5,3,6,7};
//     vector <int> result=maxSlidingWindow(nums,k);
//     for(int i=0;i<6;i++){
//         cout<<result[i]<<" ";
//     }
// return 0;
// }