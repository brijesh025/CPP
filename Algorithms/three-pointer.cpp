/*This method is used to reaarrane the nodes links on linked list
1.reversing the linked list
2.swapping nodes in pair
We take three pointers prev,crnt,next and use them as required*/\
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=nullptr;
    }
};
class linked_list{
    public:
    node* head;
    linked_list(){
        head=nullptr;
    }
    void push(int data){
        node* new_node=new node(data);
        if(head==nullptr){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new_node;
    }
};
void reverse_ll(node*& head) {
    node* prev = nullptr;
    node* crnt = head;
    node* next = nullptr;
    while (crnt) {
        next = crnt->next;
        crnt->next = prev;
        prev = crnt;
        crnt = next;
    }
    head = prev;
}
int main(){
    linked_list l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.push(6);
    node* temp=l.head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    reverse_ll(l.head);
    temp=l.head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}