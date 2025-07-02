// 1.STACK USING ARRAY;
// #include <bits/stdc++.h>
// using namespace std;
// class stacks{
//     int capacity;
//     int* arr;
//     int top;
// public:
//     stacks(int c){
//         this->capacity=c;
//         arr=new int[c];
//         this->top=-1;
//     }
//     bool isEmpty(){
//        return top==-1;
//     }
//     bool isFull(){
//         return top==capacity-1;
//     }
//     int gettop(){
//         if(top<0){
//             cout<<"underflow";
//             return -1;
//         }
//         return arr[top];
//     }
//     void push(int val){
//         if(top==capacity-1){
//             cout<<"OVERFLOW";
//             return;
//         }
//         arr[++top]=val;
//     }
//     int pop(){
//         if(top<0){
//             cout<<"UNDERFLOW";
//             return -1;
//         }
//         return arr[top--];
//     }
// };
// int main(){
//     stacks s(4);
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     cout<<s.pop();
//     cout<<s.gettop();
//     s.push(9);
//     s.push(10);
// return 0;
// }

// 2.STACK USING LINKEDLIST
// #include <bits/stdc++.h>
// using namespace std;
// class node{
// public:
//     int val;
//     node* next=NULL;
//     node(int data){
//         val=data;
//         next=NULL;
//     }
// };
// class stacks{
//     node* head;
//     int capacity;
//     int size;
// public:
//     stacks(int c){
//         capacity=c;
//         head=NULL;
//         size=0;
//     }
//     bool isEmpty(){
//         return head==NULL;
//     }
//     bool isFull(){
//         return size==capacity;
//     }
//     int gettop(){
//         if (head==NULL){
//             cout<<"UNDER FLOW";
//             return 0;
//         }
//         return head->val;
//     }
//     void push(int value){
//         if(size==capacity) {
//             cout<<"OVER FLOW";
//             return;
//         }
//         node* new_node=new node(value);
//         new_node->next=head;
//         head=new_node;
//         size++;
//         }
//     int pop(){
//         if(head==NULL){
//             cout<<"UNDER FLOW";
//             return 0;
//         }
//         node* temp=head;
//         head=head->next;
//         size--;
//         return temp->val;
//     }
// };
// int main(){
// stacks s(5);
// s.push(1);
// s.push(2);
// s.push(3);
// s.push(4);
// s.push(5);
// cout<<s.pop();
// cout<<s.pop();
// cout<<s.gettop( );
// return 0;
// }

// 3.STACK USING QUE
#include <iostream>
#define MAX_SIZE 5
using namespace std;
class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
public:
    Queue(){
        front=rear=-1;
    }
    bool is_empty() {
        return front == -1;
    }
    bool is_full() {
        return (rear + 1) % MAX_SIZE == front;
    }
    void enqueue(int data) {
        if (is_full()) {
            cout << "Queue is full\n";
            return;
        }
        if (is_empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = data;
    }
    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    int front_element() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};
class stacks{
    Queue q;
    public:
    stacks(){
        
    }
    bool is_empty(){
        return q.is_empty();
    }
    bool is_full(){
        return q.is_full();
    }
    int peek(){
        Queue temp_q;
        int ans;
        while(!q.is_empty()){
            ans=q.front_element();
            temp_q.enqueue(ans);
            q.dequeue();
        }
        while(!temp_q.is_empty()){
            q.enqueue(temp_q.front_element());
            temp_q.dequeue();
        }
        return ans;
    }
    void push(int data){
        q.enqueue(data);
    }  
    void pop(){
       Queue temp_q;
        while(!q.is_empty()){
            temp_q.enqueue(q.front_element());
            q.dequeue();
        }
        while(!temp_q.is_empty()){
            int ans=temp_q.front_element();
            temp_q.dequeue();
            if (!temp_q.is_empty())q.enqueue(ans);
        }
    } 
};
int main() {
    stacks s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.push(5);
    s.pop();
    cout<<s.peek();
}
