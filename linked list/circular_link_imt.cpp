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
class circular_linkedlist{
    public:
    node* head;
    circular_linkedlist() {
        head=nullptr;
        }
    void head_insert(int data){
        node* new_node=new node(data);
        node* tail;
        if(head==nullptr){
            head=new_node;
            new_node->next=head;
            tail=head;
        }
        new_node->next=head;
        tail->next=new_node;
        tail=tail->next;
        head=new_node;
    }
    void tail_insert(int data){
        node* new_node=new node(data);
        node* tail;
        if(head==nullptr){
            head=new_node;
            head->next=head;
            tail=head;
        }
        new_node->next=head;
        tail->next=new_node;
        tail=tail->next;
    }
    void display(){
        node* temp=head;
        do
        {
            cout<<temp->val<<" "<<temp->next<<"->";
            temp=temp->next; 
        } while (temp!=head);
        cout<<endl;   
    }
};
int main(){
circular_linkedlist l;
l.tail_insert(1);
l.tail_insert(2);
l.tail_insert(3);
l.tail_insert(4);
l.tail_insert(5);
l.tail_insert(6);
l.head_insert(7);
l.display();
circular_linkedlist l1;
l1.tail_insert(11);
l1.tail_insert(21);
l1.tail_insert(31);
l1.tail_insert(41);
l1.tail_insert(51);
l1.tail_insert(61);
l1.head_insert(71);
l1.display();
return 0;
}