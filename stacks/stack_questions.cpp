// // 1.COPY STACK
// #include <bits/stdc++.h>
// #include<stack>
// using namespace std; 
// void copy_stack(stack<int> &s1,stack<int> &s3){
//     if(s1.empty()) return;
//     int crnt=s1.top();
//     s1.pop();
//     copy_stack(s1,s3);
//     s3.push(crnt);
// }
// int main(){
//     stack <int> s1,s2,s3;
//     s1.push(1);
//     s1.push(2);
//     s1.push(3);
//     s1.push(4);
//     s1.push(5);
//     // while(!s1.empty()){
//     //     s2.push(s1.top());
//     //     s1.pop();
//     // }
//     // while(!s2.empty()){
//     //     s3.push(s2.top());
//     //     s2.pop();
//     // }
//     copy_stack(s1,s3);
//     while(!s3.empty()){
//         cout<<s3.top()<<" ";
//         s3.pop();
//         }   
// return 0;
// }

// 2.BRACKET ELEGIBILITY TEST
// #include<bits/stdc++.h>
// using namespace std;
// class stacks{
//     int data[INT16_MAX];
//     int top;
// public:
//     stacks(){
//         top=-1;
//     } 
//     bool isEmpty(){
//         return top==-1;
//     }
//     int tops(){
//         return data[top];
//     }
//     int pop(){
//         return data[top--];
//     }
//     void push(int val){
//         data[++top]=val;
//     }
// };
// bool exp_chk(string s){
//     stacks brac_hold;
//     for(char &c:s){
//         if (c=='[' or c=='{' or c=='(') brac_hold.push(c);
//         else if(c==')'){
//             if(c-brac_hold.tops()!=1) {
//                 return 0;}
//             else {
//                 brac_hold.pop();
//                 continue;}
//         }
//         else if(c=='}' or c==']'){
//             if(c-brac_hold.tops()!=2) return 0;
//             else {
//                 brac_hold.pop();
//                 continue;}
//         }
//     }
//     return brac_hold.isEmpty();
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<exp_chk(s);
// }

// 4.INSERT AT ANY INDEX
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     stack <int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     stack <int> temp;
//     int pos,val;
//     cin>>pos>>val;
//     for(int i=1;i<=pos;i++){
//         temp.push(s.top());
//         s.pop();
//     }
//     s.push(val);
//     while(not temp.empty()){
//         s.push(temp.top());
//         temp.pop();
//     }
//     while(not s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
// return 0;
// }

// 5.STACK REVERSE
// #include <bits/stdc++.h>
// using namespace std;
// void insert_bottom(stack <int> &s,int val){
//     stack<int> temp;
//     while(not s.empty()){
//         temp.push(s.top());
//         s.pop();
//     }
//     s.push(val);
//     while(not temp.empty()){
//         s.push(temp.top());
//         temp.pop();
//     }  
// }
// void reverse(stack <int> &s){
//     if(s.empty()) return;
//     int crnt=s.top();
//     s.pop();
//     reverse(s);
//     insert_bottom(s,crnt);
// }
// int main(){
// stack <int> s;
// s.push(1);
// s.push(2);
// s.push(3);
// s.push(4);
// s.push(5);
// reverse(s);
// while(not s.empty()){
//     cout<<s.top()<<" ";
//     s.pop();
// }
// return 0;
// }

// 6.NEXT GREATER ELEMENT 

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> nge(vector<int> arr,int size){
//     vector <int> nge_arr(size,-1); 
//     stack <int> hold_ind;
//     hold_ind.push(0);
//     for(int i=1;i<size;i++){
//         while (!hold_ind.empty() and arr[hold_ind.top()]<arr[i]){
//             nge_arr[hold_ind.top()]=arr[i];
//             hold_ind.pop();
//         }
//         hold_ind.push(i);
//     }
//     return nge_arr;
// }
// int main(){
//     int size;
//     cin>>size;
//     vector<int> v(size);
//     for(int &i:v) cin>>i;
//     vector<int> res=nge(v,size);
//     for(int &i:res) cout<<i<<" ";
// return 0;
// }

// 7.NEXT SMALLER ELEMENT
// #include <bits/stdc++.h>
// using namespace std;
// vector <int> nse(vector<int>arr){
//     vector <int> nse_arr(arr.size(),-1);
//     stack <int> hold_ind;
//     for(int i=0;i<arr.size();i++){
//         while(!hold_ind.empty() and arr[hold_ind.top()]>arr[i]){
//             nse_arr[hold_ind.top()]=arr[i];
//             hold_ind.pop();
//         }
//         hold_ind.push(i);
//     }
//     return nse_arr;
// }
// int main(){
//     int size;
//     cin>>size;
// vector <int> arr(size);
// for(int &i:arr)cin>>i;
// arr=nse(arr);
// for(int &i:arr)cout<<i<<" ";
// return 0;
// }


// 8.Span stocks
// #include <iostream>
// #include <stack>
// using namespace std;
// int* span(int stock[], int size){
//     int* output = new int[size];
//     stack<int> hold_ind;   
//     for(int i = size-1; i >= 0; i--){
//         while(!hold_ind.empty() && stock[i] > stock[hold_ind.top()]){
//             output[hold_ind.top()] = hold_ind.top()-i;
//             hold_ind.pop();
//         }
//         hold_ind.push(i);
//     }  
//     while(!hold_ind.empty()){
//         output[hold_ind.top()] = 1;
//         hold_ind.pop();
//     }   
//     return output;
// }
// int main(){
//     int size;
//     cin >> size;
//     int stock[size];
//     for(int i = 0; i < size; i++){
//         cin >> stock[i];
//     }   
//     int* output = span(stock, size);   
//     for(int i = 0; i < size; i++){
//         cout << output[i] << " ";
//     }
//     return 0;
// }

// 9.HISTOGRAM MAX_AREA

// A.SEPERATE CALCULATE
// #include <bits/stdc++.h>
// using namespace std;
// int* breadths(int height[],int size){
//     int* breadth=new int[size];
//     stack <int> frnt_hold_ind;
//     stack <int> bck_hold_ind;
//     for(int i=0;i<size;i++){
//         while(!frnt_hold_ind.empty() and height[frnt_hold_ind.top()]>=height[i]){
//             breadth[frnt_hold_ind.top()]=i-frnt_hold_ind.top();
//             frnt_hold_ind.pop();
//         }
//         frnt_hold_ind.push(i);
//     }
//     while(!frnt_hold_ind.empty()) {
//         breadth[frnt_hold_ind.top()]=size-frnt_hold_ind.top();
//         frnt_hold_ind.pop();}
//     for(int i=size-1;i>=0;i--){       
//             while(!bck_hold_ind.empty() and height[bck_hold_ind.top()]>=height[i]){
//                 breadth[bck_hold_ind.top()]+=bck_hold_ind.top()-i-1;
//                 bck_hold_ind.pop();
//             }
//             bck_hold_ind.push(i);
//             }   
//     while(!bck_hold_ind.empty()) {
//         breadth[bck_hold_ind.top()]+=bck_hold_ind.top();
//         bck_hold_ind.pop();}
//             return breadth;
// }
// int main(){
//     int size;
//     cin>>size;
//     int height[size];
//     for(int &i:height) cin>>i;
//     int* breadth=breadths(height,size);
//     int max_area=0;
//     for(int i=0;i<size;i++){
//         if(max_area<height[i]*breadth[i]){
//             max_area=height[i]*breadth[i];
//         }
//     }
//     cout<<max_area;
// return 0;
// }

// B.SINGLE CALCULATION
// #include <bits/stdc++.h>
// using namespace std;
// int max_area(int height[],int size){
//     stack <int> hold_ind;
//     int cal_max_area=0;
//     for(int i=0;i<size;i++){
//         while(!hold_ind.empty() and height[hold_ind.top()]>height[i]){
//             int nse=i;
//             int curr_height=height[hold_ind.top()];
//             hold_ind.pop();
//             int pse=(hold_ind.empty())? (-1):hold_ind.top();
//             int curr_max_area=curr_height*(nse-pse-1);
//             if(cal_max_area<curr_max_area) cal_max_area=curr_max_area;
//         }
//     hold_ind.push(i);
//     }
//     while(!hold_ind.empty()){
//         int nse=size;
//         int curr_height=height[hold_ind.top()];
//         hold_ind.pop();
//         int pse=(hold_ind.empty())? (-1):hold_ind.top();
//         int curr_max_area=curr_height*(nse-pse-1);
//         if(cal_max_area<curr_max_area) cal_max_area=curr_max_area;
//     }
//     return cal_max_area;
// }
// int main(){
//     int size;
//     cin>>size;
//     int height[size];
//     for(int &i:height) cin>>i;
//     cout<<max_area(height,size);
// }

// A.X-MINM PROBLEM
// #include <bits/stdc++.h>
// using namespace std;
// class stacks{
//     int top_i;
//     int minm;
//     int stack_arr[INT16_MAX];
// public:
//     stacks(){
//         top_i=-1;
//         minm=INT16_MAX;
//     }
//     void push(int data){
//         if(top_i==-1){
//             stack_arr[++top_i]=data;
//             minm=data;
//         }
//         else{
//             stack_arr[++top_i]=data-minm;
//             if(minm>data) minm=data;
//     }
//     }
//     void pop(){
//         if(stack_arr[top_i]<0){
//             minm=minm-stack_arr[top_i--];
//         }
//         else top_i--;
//     }
//     int top(){
//         if(top_i==0) return stack_arr[top_i--];
//         else if(stack_arr[top_i]>=0) return stack_arr[top_i--]+minm;
//         else{
//             top_i--;
//             return minm;
//         }
//     }
//     int getMin(){
//         return minm;
//     }
// };
// int main(){
//     stacks s;
//     s.push(5);
//     cout<<s.getMin()<<endl;
//     s.push(-9);
//     s.push(0);
//     s.push(10);
//     s.push(8);
//     s.pop();
//     cout<<s.getMin()<<endl;
//     s.push(-99);
//     s.pop();
//     cout<<s.getMin()<<endl;
//     s.push(-8);
//     s.pop();
//     s.push(-100);
//     cout<<s.getMin()<<endl;
// return 0;
// }
