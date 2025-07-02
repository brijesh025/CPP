// 1.Delete same and alternate elements
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* next;
// };
// void input(node* &head,int size){
//     node* temp=head;
//     for(int i=1;i<size;i++){
//         node* new_node=new node();
//         cin>>new_node->val;
//         temp->next=new_node;
//         temp=temp->next;
//     }
//     temp->next=NULL;
// }
// void output(node* &head){
//     node* temp=head;
//     while(temp->next!=NULL){
//         cout<<temp->val<<" "<<temp->next<<"->";
//         temp=temp->next;
//     }
//         cout<<temp->val<<" "<<temp->next;
// }
// void del_alt(node* head){
//     node* temp=head;
//     while(temp->next!=NULL){
//         node *curr_node=temp->next;
//         if(temp->next->next==NULL){
//         temp->next=temp->next->next;
//         return;
//         }
//         temp->next=temp->next->next;
//         temp=temp->next;
//         free(curr_node);
//     }
// }
// void del_same(node* &head){
//     node* temp=head;
//     while(temp->next!=NULL){
//         if(temp->val==temp->next->val){
//             temp->next=temp->next->next;
//             continue;
//         }
//         temp=temp->next;
//     }
// }
// int main(){
//     int size;
//     cin>>size;
//     node* head=new node;
//     cin>>head->val;
// input(head,size);
// // del_alt(head);
// del_same(head);
// output(head);
// return 0;
// }

// 2.reverse order of linked_list
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     int val;
//     node* next;
// public:
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
//     void tail_insert(int data,node* head){
//         node* tail;
//         if(head->next==nullptr) tail=head;
//             node* temp=new node(data);
//             tail->next=temp;
//             tail=tail->next;
//     }
//     void reverse_node_print(node* head){
//         if(head==nullptr) return;
//         reverse_node_print(head->next);
//         cout<<head->val<<" ";
//     }
//     node* reverse_linkedlist(node* &head){
//         if(head==nullptr or head->next==nullptr) return head;
//         node* temp=reverse_linkedlist(head->next);
//         head->next->next=head;
//         head->next=nullptr;
//         return temp;
//     }
//     void print_ll(node* head){
//         while(head!=nullptr){
//         cout<<head->val<<" ";
//        head=head->next;
//     }
//     }
// };
// int main(){
//     node* head=new node(1);
//     head->tail_insert(2,head);
//     head->tail_insert(3,head);
//     head->tail_insert(4,head);
//     head->tail_insert(5,head);
//     // head->reverse_node_print(head);
//     head=head->reverse_linkedlist(head);
//     head->print_ll(head);
// return 0;
// }

// 3.compare linked list
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     int val;
//     node* next;
// public:
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
//     void tail_insert(int data,node* head){
//         node* tail;
//         if(head->next==nullptr) tail=head;
//         node* temp=new node(data);
//         tail->next=temp;
//         tail=tail->next;
//     }
//     bool compare(node* head1,node* head2){
//         node* temp1=head1;
//         node* temp2=head2;
//         while(temp1!=nullptr and temp2!=nullptr){
//             if(temp1->val!=temp2->val) return 0;
//         temp1=temp1->next;
//         temp2=temp2->next;
//         }
//         return (temp1==nullptr and temp2==nullptr);
//     }
// };
// int main(){
//     node* head1=new node(1);
//     node* head2=new node(1);
//     head1->tail_insert(2,head1);
//     head1->tail_insert(3,head1);
//     head1->tail_insert(4,head1);
//     head2->tail_insert(2,head2);
//     head2->tail_insert(3,head2);
//     // head2->tail_insert(4,head2);
//     cout<<head1->compare(head1,head2);
// return 0;
// }

// 4.return intersection of two linked list
// #include <bits/stdc++.h>
// using namespace std;
// class node{
// public:
//     int val;
//     node* next;
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
// };
// class linkedlist{
//     node* head;
// public:
//     linkedlist(){
//         head=nullptr;
//     }
//     void insert(int data){
//         node* tail;
//         node* new_node=new node(data);
//         if(head==nullptr) {
//             head=new_node;
//             tail=head;
//             }
//         tail->next=new_node;
//         tail=tail->next;
//     }
//     void display(){
//         node* temp=head;
//         while(temp!=nullptr){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     int size(){
//         int cnt=0;
//         node* temp=head;
//         while(temp!=nullptr){
//             cnt++;
//             temp=temp->next;
//         }
//         return cnt;
//     }
//     void del_from_last(int k){
//         int from_strt=size()-k+1;
//         node* temp=head;
//         if (from_strt==1){
//             head=head->next;
//             return;
//         }
//         int cnt=1;
//         while(cnt!=from_strt-1){
//             temp=temp->next;
//             cnt++;
//         }
//         temp->next=temp->next->next;
//         return;
//     }
// };
// int main(){
//     linkedlist ll1;
//     ll1.insert(1);
//     ll1.insert(2);
//     ll1.insert(3);
//     ll1.insert(4);
//     ll1.insert(5);
//     ll1.display();
//     ll1.del_from_last(5);
//     ll1.display();
// return 0;
// }

// 5.merge sorted linked list;
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
// class linkedlist{
//     public:
//     node* head;
//     linkedlist(){
//         head=NULL;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         node* tail;
//         if(head==NULL){
//             head=new_node;
//             tail=head;
//             return;
//         }
//         tail->next=new_node;
//         tail=tail->next;
//     }
//     void display(){
//         node* temp=head;
//         while(temp!=nullptr){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     int size(){
//         int cnt=0;
//         node* temp=head;
//         while(temp!=nullptr){
//             cnt++;
//             temp=temp->next;
//         }
//         return cnt;
//     }  
// };
// node* merge_link_sorted(node* &head1,node* &head2){
//     node* merge_head=new node(-1);
//     node* pntr1=head1;
//     node* pntr2=head2;
//     node* temp=merge_head;
//     while(pntr1 and pntr2){
//         if(pntr1->val<pntr2->val){
//             temp->next=pntr1;
//             pntr1=pntr1->next;
//         }
//         else{
//             temp->next=pntr2;
//             pntr2=pntr2->next;
//         }
//         temp=temp->next;
//     }
//     if(pntr1) temp->next=pntr1;
//     else if(pntr2) temp->next=pntr2;
//     return merge_head->next;
// }
// node* merge_link(node* head1,node* head2){
//     node* merge_head=new node(-1);
//     node* pntr1=head1;
//     node* pntr2=head2;
//     node* temp=merge_head;
//     while(pntr1 and pntr2){
//         node* new_node1=new node(pntr1->val);
//         temp->next=new_node1;
//         temp=temp->next;
//         node* new_node2=new node(pntr2->val);
//         temp->next=new_node2;
//         temp=temp->next;
//         pntr1=pntr1->next;
//         pntr2=pntr2->next;
//     }
//     if(pntr1) temp->next=pntr1;
//     else if(pntr2) temp->next=pntr2;
//     return merge_head->next;
// }
// int main(){
//     linkedlist ll1;
//     ll1.insert(1);
//     ll1.insert(4);
//     ll1.insert(5);
//     ll1.display();
//     linkedlist ll2;
//     ll2.insert(2);
//     ll2.insert(3);
//     ll2.insert(8);
//     ll2.display();
//     linkedlist merge_sort_ll;
//     merge_sort_ll.head=merge_link_sorted(ll1.head,ll2.head);
//     merge_sort_ll.display();
//     // linkedlist ll3;
//     // ll3.head=merge_link(ll1.head,ll2.head);
//     // ll3.display();
// return 0;
// }

// 6.Megre array of k-linkedlist
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//         int val;
//         node* next;
//         node(int data){
//             val=data;
//             next=nullptr;
//         }
//     };
// class linkedlist{
// public:
//     node* head;
//     linkedlist(){
//         head=nullptr;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         node *tail;
//         if(head==nullptr){
//             head=new_node;
//             tail=head;
//         }
//         tail->next=new_node;
//         tail=tail->next;
//     }
//     void print(){
//         node* temp=head;
//         while(temp!=nullptr){
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// };
// linkedlist merge_link_list(linkedlist ll_arr[]){
//     static int cnt=0;
//     linkedlist merged;
//     while(cnt<2){
//     node* merged_node=new node(0);
//     node* pntr1=ll_arr[cnt++].head;
//     node* pntr2=ll_arr[cnt].head;
//     node* temp=merged_node;
//     while(pntr1 and pntr2){
//         if(pntr1->val<pntr2->val){
//             temp->next=pntr1;
//             pntr1=pntr1->next;
//         }
//         else{
//             temp->next=pntr2;
//             pntr2=pntr2->next;
//         }
//         temp=temp->next;
//     }
//     if(pntr1) temp->next=pntr1;
//     else if(pntr2) temp->next=pntr2;
//     merged.head=merged_node->next;
//     ll_arr[cnt]=merged;
//     }
//     return merged;
// }
// int main(){
//     linkedlist ll_arr[3];
//     ll_arr[0].insert(1);
//     ll_arr[0].insert(2);
//     ll_arr[0].insert(30);
//     ll_arr[0].insert(60);
//     ll_arr[0].insert(70);
//     ll_arr[1].insert(2);
//     ll_arr[1].insert(3);
//     ll_arr[1].insert(4);
//     ll_arr[1].insert(4);
//     ll_arr[1].insert(5);
//     ll_arr[2].insert(2);
//     ll_arr[2].insert(30);
//     ll_arr[2].insert(40);
//     ll_arr[2].insert(44);
//     ll_arr[2].insert(50);
//     merge_link_list(ll_arr).print();
// return 0;
// }

// 7.Slow fast pionter middle most element
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//         int val;
//         node* next;
//         node(int data){
//             val=data;
//             next=nullptr;
//         }
//     };
// class linkedlist{
// public:
//     node* head;
//     linkedlist(){
//         head=nullptr;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         node* tail;
//         if(head==nullptr) {
//             head=new_node;
//             tail=head;
//             }
//         else{
//             tail->next=new_node;
//             tail=tail->next;
//         }
//     }
// };
// node* middle_node(linkedlist l){
//     node* slow=l.head;
//     node* fast=l.head;
//     while(fast!=nullptr and fast->next!=nullptr){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }
// int main(){
// linkedlist l;
// l.insert(1);
// l.insert(2);
// l.insert(3);
// l.insert(4);
// l.insert(5);
// l.insert(6);
// cout<<middle_node(l)->val;
// return 0;
// }

// 8.chk for cycle
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    }
};
class linkedlist{
    public:
    node* head;
    linkedlist(){
        head=NULL;
    }
    void insert(int data){
        node* new_node=new node(data);
        node* tail;
        if(head==NULL){
            head=new_node;
            tail=head;
            return;
        }
        tail->next=new_node;
        tail=tail->next;
    }
    void display(){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<" "<<temp->next<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    int size(){
        int cnt=0;
        node* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }  
};
bool is_cycle(linkedlist l){
    node* slow=l.head;
    node* fast=l.head;
    while((fast!=nullptr and fast->next!=nullptr)){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}
void remove_cycle(linkedlist l){
    node* slow=l.head;
    node* fast=l.head;
    while((fast!=nullptr and fast->next!=nullptr)){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    fast=l.head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=nullptr;
}
int main(){
linkedlist l;
l.insert(1);
l.insert(4);
l.insert(3);
l.insert(4);
l.insert(5);
l.insert(6);
l.display();
l.head->next->next->next->next->next->next=l.head->next;
cout<<is_cycle(l)<<endl;
remove_cycle(l);
l.display();
cout<<is_cycle(l)<<endl;
return 0;
}