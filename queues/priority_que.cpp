// #IMPLMENTATION
#include <bits/stdc++.h>
using namespace std;
void max_heapify(int crnt, int data[], int size) {
    while ((crnt * 2 + 1) < size) {
        int l = (crnt * 2) + 1; // Left child
        int r = (crnt * 2) + 2; // Right child
        int m = l;
        if (r < size && data[r] > data[l]) m = r;
        if (data[crnt] > data[m]) return;
        else {
            swap(data[crnt], data[m]);
            crnt = m;
        }
    }
}
void increase_pri(int data[], int size, int crnt) {
    while (crnt >= 0) {
        int parent = (crnt) / 2;
        if (data[crnt] > data[parent]) {
            swap(data[crnt], data[parent]);
            crnt = parent;
        } else break;
    }
}
class priority_que {
    int data[100];
public:
    int size;
    int capacity;
    priority_que(int len) {
        size = 0;
        capacity = len;
    }
    bool empty() {
        return size == 0;
    }
    int front() {
        if (size == 0) return -1;
        return data[0];
    }
    void enque(int element) {
        if (size == capacity) return;
        data[size] = element;
        increase_pri(data, size, size);
        size++;
    }
    void deque() {
        if (size == 0) return;
        swap(data[0], data[size - 1]);
        size--;
        max_heapify(0, data, size);
    }
};
int main() {
    priority_que q(10);
    q.enque(3);
    q.enque(8);
    q.enque(1);
    q.enque(6);
    q.enque(5);
    q.enque(45);
    q.enque(50);
    q.enque(9);
    q.enque(10);
    q.enque(32);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.deque();
    }
    return 0;
}

// 1.kth largest element

// A.USING MAX HEAP-->O(n+klog(n))
// #include <bits/stdc++.h>
// using namespace std;
// void max_heapify(int crnt, int data[], int size) {
//     while ((crnt * 2 + 1) < size) {
//         int l = (crnt * 2) + 1; // Left child
//         int r = (crnt * 2) + 2; // Right child
//         int m = l;
//         if (r < size && data[r] > data[l]) m = r;
//         if (data[crnt] > data[m]) return;
//         else {
//             swap(data[crnt], data[m]);
//             crnt = m;
//         }
//     }
// }
// void increase_pri(int data[], int size, int crnt) {
//     while (crnt > 0) {
//         int parent = (crnt-1) / 2;
//         if (data[crnt] > data[parent]) {
//             swap(data[crnt], data[parent]);
//             crnt = parent;
//         } else break;
//     }
// }
// class priority_que {
//     int data[100];
// public:
//     int size;
//     int capacity;
//     priority_que(int len) {
//         size = 0;
//         capacity = len;
//     }
//     bool empty() {
//         return size == 0;
//     }
//     int front() {
//         if (size == 0) return -1;
//         return data[0];
//     }
//     void enque(int element) {
//         if (size == capacity) return;
//         data[size] = element;
//         increase_pri(data, size, size);
//         size++;
//     }
//     void deque() {
//         if (size == 0) return;
//         swap(data[0], data[size - 1]);
//         size--;
//         max_heapify(0, data, size);
//     }
// };
// int main() {
//     int size,k;
//     cin>>size>>k;
//     int arr[size];
//     priority_que q(size);
//     for(int &i:arr){
//         cin>>i;
//         q.enque(i);
//     }
//     for(int i=k;i>1;i--) {
//         q.deque();
//     }
//     cout<<q.front();
//     return 0;
// }

// B.USING MIN HEAP-->O(nlog(k))
// #include <bits/stdc++.h>
// using namespace std;
// void min_heapify(int crnt, int data[], int size) {
//     while ((crnt * 2 + 1) < size) {
//         int l = (crnt * 2) + 1; // Left child
//         int r = (crnt * 2) + 2; // Right child
//         int m = l;
//         if (r < size && data[r] < data[l]) m = r;
//         if (data[crnt] < data[m]) return;
//         else {
//             swap(data[crnt], data[m]);
//             crnt = m;
//         }
//     }
// }
// void increase_pri(int data[], int size, int crnt) {
//     while (crnt > 0) {
//         int parent = (crnt) / 2;
//         if (data[crnt] < data[parent]) {
//             swap(data[crnt], data[parent]);
//             crnt = parent;
//         } else break;
//     }
// }
// class priority_que {
//     int data[100];
// public:
//     int size;
//     int capacity;
//     priority_que(int len) {
//         size = 0;
//         capacity = len;
//     }
//     bool empty() {
//         return size == 0;
//     }
//     int front() {
//         if (size == 0) return -1;
//         return data[0];
//     }
//     void enque(int element) {
//         if (size == capacity) return;
//         data[size] = element;
//         increase_pri(data, size, size);
//         size++;
//     }
//     void deque() {
//         if (size == 0) return;
//         swap(data[0], data[size - 1]);
//         size--;
//         min_heapify(0, data, size);
//     }
//     int lenght(){
//         return size;
//     }
// };
// int main() {
//     int size,k;
//     cin>>size>>k;
//     int arr[size];
//     priority_que q(size);
//     for(int i=0;i<size;i++){
//         cin>>arr[i]; 
//     }
//     for(int i=k;i<size;i++){
//         q.enque(arr[i]); 
//         if(q.lenght()>k){
//             q.deque();
//         }
//     }
//     cout<<q.front();
// }

