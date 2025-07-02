// 1.USING ARRAY
#include <bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    int array[size];
    for (int &i:array)
    {
        cin>>i;
    }
    for (int i = 0; i < size; i++)
    {
        int minmind=i;
        for (int j = i; j <size; j++)
        {
            if(array[minmind]>array[j]) {
                minmind=j;
            }
        }
            swap(array[i],array[minmind]);
        }
    for (int &i:array)
    {
        cout<<i<<" ";
    }
return 0;
}


// 2.USING LINKED LIST
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* next;
//     node(int data){
//         val=data;
//         next=nullptr;
//     }
// };
// class linked_list{
//     node* head;
//     public:
//     linked_list(){
//         head=nullptr;
//     }
//     void insert(int data){
//         node* new_node=new node(data);
//         node* tail;
//         if(head==nullptr){
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
// };
// int main(){
// linked_list l;
// l.insert(1);
// l.insert(2);
// l.insert(3);
// l.insert(4);
// l.insert(5);
// l.insert(6);
// l.display();
// return 0;
// }