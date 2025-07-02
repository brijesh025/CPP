#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* pre;
    node* next;
    node(int data){
        val=data;
        pre=NULL;
        next=NULL;
    }
};
class doub_linkedlist{
public:
    node* head;
    node* tail;
    doub_linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void head_insert(int val){
        node* new_node=new node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->pre=new_node;
        head=new_node;
        return;
    }
    void tail_insert(int val){
        node* new_node=new node(val);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->pre=tail;
        tail->next=new_node;
        tail=new_node;
        return;
    }
    void pos_insert(int val,int pos){
        node* new_node=new node(val);
        if(pos==0){
            head_insert(val);
            return;

        }
        node* temp=head;
        while(--pos!=0){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->pre=temp;
        return;
    }
    void output(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->pre<<" "<<temp->val<<" "<<temp->next<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void del_pos(int pos){
            node* temp=head;
               if(pos==0){
                head->next->pre=NULL;
                head=temp->next;
                free(temp);
               }
               while(--pos!=0){
                temp=temp->next;
               }
               node* f_temp=temp->next;
               if(temp->next->next==NULL){
                tail=temp;
                temp->next=NULL;
                free(f_temp);
                return;
               }
               temp->next=temp->next->next;
               temp->next->pre=temp;
                free(f_temp);
               
    }

};
int main(){
    doub_linkedlist l;
    l.head_insert(1);
    l.head_insert(2);
    l.head_insert(3);
    l.tail_insert(4);
    l.output();
    l.del_pos(2);
    l.output();
return 0;
}