// 1.DELETE LAST NODE
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* next;
    node* pre;
    node(int data){
        val=data;
        next=nullptr;
        pre=nullptr;
    }
};
class double_linkedlist{
public:
    node* head;
    node* tail;
    double_linkedlist(){
        head=nullptr;
        tail=nullptr;
    }
    void insert(int data){
        node* new_node=new node(data);
        if(head==nullptr){
            head=new_node;
            tail=new_node;
        }
        else {
            new_node->pre=tail;
            tail->next=new_node;
            tail=tail->next;
            }
    }
    void display(){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->pre<<" "<<temp->val<<" "<<temp->next<<"->";
            temp=temp->next;
        }
        cout<<"null"<<endl;
    }
    void delete_last_node(){
        node* temp=tail;
        tail=tail->pre;
        tail->next=nullptr;
        free(temp);
    }
};
int main(){
    double_linkedlist l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.display();
    l.delete_last_node();
    l.display();
return 0;
}