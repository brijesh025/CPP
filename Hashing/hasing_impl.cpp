// 1.hash table using closed addressing->separate chaining

// A.WITHOUT STL
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
    void add(int data){
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
    void display(){
        node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
class linear_hashing{
    int *arr;
    int size;
    public:
    linear_hashing(int data){
        size=data;
        arr=new int[size];
        for(int i=0;i<size;i++)arr[i]=-1;
    }
    ~linear_hashing() {
        delete[] arr; 
        }
    void insert(int data){
        int i=0;
        while(true){
            int h=(data+i)%size;
            if(arr[h]==-1){arr[h]=data;
            return;
            }
            if(i==size)return;
            i++;
        }
    }
    void display(){
        for(int i=0;i<size;i++) cout<<arr[i]<<endl;
    }
    bool find(int data){
        int i=0;
        while(true){
        int h=(data+i)%size;
        if(arr[h]==-1) return false;
        else if(arr[h]==data) return true;
        if(i==size) return false;
        i++;
        }
            }
};
class hashing{
    linked_list hash_table[INT16_MAX];
    int buckets;
    public:  
    hashing(int size){
        buckets=size;
    }
    void add(int data){
        hash_table[data%buckets].add(data);
    }
    void display(){
        int i=buckets-1;
        while(i--){
            hash_table[i].display();
        }
    }
};
int main(){
    hashing h(10);
    h.add(1);
    h.add(2);
    h.add(21);
    h.add(12);
    h.add(14);
    h.add(10);
    h.add(4);
    h.add(54);
    h.add(16);
    h.add(17);
    h.add(7);
    h.add(8);
    h.add(18);
    h.add(498);
    h.add(102);
    h.display();
    linear_hashing l(10);
    l.insert(1);
    l.insert(11);
    l.insert(12);
    l.insert(16);
    l.insert(7);
    l.insert(8);
    l.insert(98);
    l.insert(94);
    l.insert(21);
    l.insert(68);
    l.display();
    cout<<l.find(94);
return 0;
}

// B.WITH STL
// #include <bits/stdc++.h>
// using namespace std;
// class hashing{
//     vector<list<int>> hash_table;
//     int buckets;
//     public:
//     hashing(int data){
//         buckets=data;
//         hash_table.resize(buckets);
//     }
//     int hash_value(int data){
//         return data%buckets;
//     }
//     void add(int data){
//         hash_table[hash_value(data)].push_back(data);
//     }
//     void delete_ele(int data){
//         int idx=hash_value(data);
//         if(search(data)!=hash_table[idx].end()){
//             hash_table[idx].erase(search(data));
//             cout<<"deleted"<<endl;
//         }
//     }
//     list<int>::iterator search(int data){
//         int idx=hash_value(data);
//         return find(hash_table[idx].begin(),hash_table[idx].end(),data);
//     }
// };
// int main(){
//     hashing h(10);
//     h.add(1);
//     h.add(5);
//     h.add(4);
//     h.add(45);
//     h.add(78);
//     h.add(79);
//     h.add(8);
//     h.add(11);
//     h.add(12);
//     h.add(112);
//     h.add(110);
//     h.add(40);
//     h.add(19);
//     h.add(9);
//     h.add(56);
//     h.delete_ele(11);
// return 0;
// }