// A.FIRST WAY
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* next;
//     node(int data){
//         val=data;
//         next=NULL;
//     }
// };
// void head_insert(int val,node* &head){
//     node *new_node=new node(val);
//     new_node->next=head;
//     head=new_node;
// }
// void tail_insert(int val,node* head){
//     node *new_node=new node(val);
//     node* temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=new_node;
// }
// void display(node* head){
//     node* temp=head;
//     while (temp!=NULL)
//     {
//         cout<<temp->val<<"->";
//         temp=temp->next;    
//     }
//     cout<<"NULL"<<endl;
// }
// void pos_insert(int val,int pos,node* &head){
//     if(pos==0) {
//         head_insert(val,head);
//         return;
//     }
//     else{
//         node* temp=head;
//         int cnt=0;
//         while(cnt!=pos-1){
//             temp=temp->next;
//             cnt++;
//             }
//             node* new_node=new node(val);
//             new_node->next=temp->next;
//             temp->next=new_node;
//                 return;
//         }
//     }
// void update(int val,int pos,node *head){
//     int cnt=0;
//     node* temp=head;
//     while(pos!=cnt){
//         temp=temp->next;
//         cnt++;
//     }
//     temp->val=val;
// }
// void pos_delete(int pos,node* &head){
//     node* temp=head;
//     if(pos==0){
//         head=head->next;
//         free(temp);
//         return;
//     }
//     int cnt=0;
//     node* pre_pos=head;
//     while(cnt!=pos-1){
//         pre_pos=pre_pos->next;
//         cnt++;
//     }
//     temp=pre_pos->next;
//     pre_pos->next=pre_pos->next->next;
//     free(temp);
// }
// int main(){
//     node* head=NULL;
//     head_insert(2,head);
//     display(head);
//     head_insert(1,head);
//     display(head);
//     tail_insert(3,head);
//     display(head);
//     pos_insert(0,1,head);
//     display(head);
//     update(1,2,head);
//     display(head);
//     pos_delete(0,head);
//     display(head);
// return 0;
// }

// B.SECOND WAY

#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node *next;
    node(int data)
    {
        val = data;
        next = nullptr;
    }
};
class linkedlist{
public:
    node* head;
    linkedlist(){
        head=nullptr;
    }
    void temp_insert(int val){
        node* new_node=new  node(val);
        if(head==nullptr){
            head=new_node;
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void insert(int val){
        node* new_node=new node(val);
        node* temp;
        if(head==nullptr){
            head=new_node;
            temp=head;
            return;
        }
        temp->next=new_node;
        temp=temp->next;
    }
    void display(){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp<<" "<<temp->val<<" -> ";
            temp=temp->next;
        }cout<<"NULL";
    }
      
};
int main(){
    linkedlist l;
    l.insert(1);
    node* new_node=new node(-100);
    l.insert(2);
    new_node=new node(-100);
    delete(new_node);
    new_node=new node(-100);
    delete(new_node);
    l.insert(3);
    l.insert(4);
    new_node=new node(-100);
    delete(new_node);
    new_node=new node(-100);
    delete(new_node);
    new_node=new node(-100);
    delete(new_node);
    l.insert(5);
    new_node=new node(-100);
    delete(new_node);
    l.temp_insert(9);
    new_node=new node(-100);
    delete(new_node);
    new_node=new node(-100);
    delete(new_node);
   new_node=new node(-100);
   delete(new_node);
    l.insert(6);
    new_node=new node(-100);
    delete(new_node);
    l.display();
    return 0;
}