// 1.linked list implementation
// #include <bits/stdc++.h>
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
//     node* head;
//     node* tail;
//     int size;
//     int capacity;
//     public:
//     queues(int c){
//         head=NULL;
//         tail=NULL;
//         size=0;
//         capacity=c;
//     }
// int length(){
//         return size;
//     }
// bool isEmpty(){
        //    return size==0;
        //    }
// bool isFull(){
//         return size==capacity;
//     }
// int front_ele(){
//     if(head==NULL){
//         cout<<"under flow";
//         return 0;
//     }
//     return head->val;
// }
// void enqueue(int data){
//         if(size==capacity){
//             cout<<"over flow";
//             return;
//         }
//         node* new_node=new node(data);
//         if(head==NULL){
//             head=new_node;
//             tail=new_node;
//             size++;
//             return;
//         }
//         else{
//             tail->next=new_node;
//             tail=tail->next;
//             size++;
//         }
//     }
// void dequeue(){
//         if(head==NULL){
//             cout<<"under flow";
//             return;
//         }
//         node*  temp=head;
//         head=head->next;
//         size--;
//         free(temp);
//         if(head==NULL){
//             tail=NULL;
//         }
//     }
// };
// int main(){
//     queues q(5);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);
//     cout<<q.front()<<endl;
//     q.dequeue();
//     cout<<q.front_ele()<<endl;
//     cout<<q.length();
// return 0;
// }


//2. ARRAY IMPLEMENTATION
// #include <bits/stdc++.h>
// using namespace std;
// class queues{
//     int front;
//     int back;
//     int capacity;
//     vector <int> v;
// public:
// queues(int c){
//         front=-1;
//         back=-1;
//         capacity=c;
//         }
// bool isEmpty(){
//         return front==-1;
//     }
// bool isFull(){
//         return capacity==(back-front+1);
//     }
// int length(){
//         return back-front+1;
//     }
// int front_ele(){
//     if(front==-1) return -1;
//         return v[front];
//     }
// void enqueue(int data){
//         v.push_back(data);
//         back++;
//         if(back==0) front=0;
//     }
// void dequeue(){
//         if(front==back){
//             front=-1;
//             back=-1;
//             v.clear();
//             return;
//         }
//         front++;
//     }
// };
// int main(){
// queues q(5);
// cout<<q.isEmpty()<<endl;
// cout<<q.isFull()<<endl;
// q.enqueue(1);
// q.enqueue(2);
// q.enqueue(3);
// q.dequeue();
// cout<<q.front_ele()<<endl;
// cout<<q.length()<<endl;
// q.enqueue(100);
// cout<<q.length();
// return 0;
// }

// 3.QUEUES USING STACK

// A.PUSH EFFICIENT
// #include <bits/stdc++.h>
// using namespace std;
// class que{
//     stack <int> s;
//     public:
//     que(){
//     }
//     void push(int data){
//         s.push(data);
//     }
//     void pop(){
//         stack <int> temp;
//         while(!s.empty()){
//             temp.push(s.top());
//             s.pop();
//         }
//         temp.pop();
//         while(!temp.empty()){
//             s.push(temp.top());
//             temp.pop();
//         }
//     }
//     bool isEmpty(){
//         return s.empty();
//     }
//     int front(){
//          stack <int> temp;
//         while(!s.empty()){
//             temp.push(s.top());
//             s.pop();
//         }
//         int front_ele=temp.top();
//         while(!temp.empty()){
//             s.push(temp.top());
//             temp.pop();
//         }
//         return front_ele;
//     }    
// };
// int main(){
//     que q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.pop();
//     cout<<q.front()<<endl;
//     q.push(5);
//     q.pop();
//     cout<<q.front()<<endl;
//     q.push(6);
//     while(!q.isEmpty()){
//         cout<<q.front()<<" ";
//         q.pop();
//     }
// return 0;
// }

// B.POP EFFICIENT 
// #include <bits/stdc++.h>
// using namespace std;
// class que{
//     stack<int> s;
//     public:
//     que(){
//     }
//     void push(int data){
//         stack <int> temp;
//         while(!s.empty()){
//             temp.push(s.top());
//             s.pop();
//         }
//         temp.push(data);
//         while(!temp.empty()){
//             s.push(temp.top());
//             temp.pop();
//         }
//     }
//     void pop(){
//         s.pop();
//     }
//     bool isEmpty(){
//         return s.empty();
//     }
//     int peek(){
//        return s.top();
//     }   
// };
// int main(){
//     que q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.push(5);
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.push(6);
//     while(!q.isEmpty()){
//         cout<<q.peek()<<" ";
//         q.pop();
//     }
// return 0;
// }

// 4.CIRCULAR QUEUES USING ARRAY

// A.
#include <bits/stdc++.h>
using namespace std;
class que{
    int* arr;
    int front_i;
    int rear_i;
    int size;
    public:
    que(int data){
        arr=new int(size);
        front_i=rear_i=-1;
        size=data;
    }
    bool is_full(){
        return (rear_i+1)%size==front_i;
    }
    bool is_empty(){
        return front_i==-1;
    }
    void enque(int data){
        if(is_full()) return;
        if(front_i==-1) front_i=0; 
        rear_i=(rear_i+1)%size;
        arr[rear_i]=data;
    }
    int deque(){
        if(is_empty()) return -1;
        int removed=arr[front_i];
        if(front_i==rear_i) front_i=rear_i=-1;
        else{
            front_i=(front_i+1)%size;
        }  
        return removed;
    }
    void display(){
        if(is_empty()) return;
        int i=front_i;
        while(i!=rear_i){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<arr[rear_i];
    cout<<endl;
    }

};
int main(){
    que q(7);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.display();
    q.deque();
    q.deque();
    q.enque(7);
    q.deque();
    q.enque(7);
    q.deque();
    q.enque(9);
    q.enque(9);
    q.enque(9);
    q.display();
return 0;
}