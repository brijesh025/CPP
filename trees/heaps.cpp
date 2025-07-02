// #IMPLEMENTAION
// A.MIN_HEAP
// #include <bits/stdc++.h>
// using namespace std;
// void insert_min_heap(int min_heap[],int &size,int value){
//     size++;
//     min_heap[size]=value;
//     int curr=size;
//     while((curr/2)>0 and min_heap[curr]<min_heap[curr/2]){
//         swap(min_heap[curr/2],min_heap[curr]);
//         curr/=2;
//     }
// }
// int main(){
//     int min_heap[INT16_MAX]={-1};
//     int size=0;
//     insert_min_heap(min_heap,size,60);
//     insert_min_heap(min_heap,size,50);
//     insert_min_heap(min_heap,size,40);
//     insert_min_heap(min_heap,size,30);
//     insert_min_heap(min_heap,size,20);
//     insert_min_heap(min_heap,size,30);
//     insert_min_heap(min_heap,size,10);
//     for(int i=0;i<=size;i++){
//         cout<<min_heap[i]<<" ";
//     }cout<<endl;
// return 0;
// }

// B.MAX_HEAP AND DELETE
// #include <bits/stdc++.h>
// using namespace std;
// void insert_max_heap(int max_heap[],int &size,int value){
//     size++;
//     max_heap[size]=value;
//     int curr=size;
//     while((curr/2)>0 and max_heap[curr]>max_heap[curr/2]){
//         swap(max_heap[curr/2],max_heap[curr]);
//         curr/=2;
//     }
// }
// void del_max_heap(int max_heap[],int &size){
//     size--;
//     int crnt=1;
//     max_heap[crnt]=max_heap[size+1];
//     while((crnt*2)<=size){
//         int leftchild=2*crnt;
//         int rightchild=(2*crnt)+1;
//         int maxchild=leftchild;
//         if(rightchild<=size and max_heap[rightchild]>max_heap[leftchild]){
//             maxchild=rightchild;
//         }
//         if(max_heap[crnt]>=max_heap[maxchild]){
//             return;
//         }
//         swap(max_heap[crnt],max_heap[maxchild]);
//         crnt=maxchild;
//     }
// }
// int main(){
//     int max_heap[INT16_MAX]={-1};
//     int size=0;
//     insert_max_heap(max_heap,size,60);
//     insert_max_heap(max_heap,size,50);
//     insert_max_heap(max_heap,size,40);
//     insert_max_heap(max_heap,size,30);
//     insert_max_heap(max_heap,size,20);
//     insert_max_heap(max_heap,size,30);
//     insert_max_heap(max_heap,size,10);
//     del_max_heap(max_heap,size);
//     for(int i=0;i<=size;i++){
//         cout<<max_heap[i]<<" ";
//     }cout<<endl;
// return 0;
// }

// #HEAPIFY

// 1.MIN_HEAP
// #include <bits/stdc++.h>
// using namespace std;
// void heapify(int arr[],int &size,int crnt){
//     while((crnt*2)<=size){
//         int leftchild=(crnt*2);
//         int rightchild=(crnt*2)+1;
//         int minchild=leftchild;
//         if(rightchild<=size and arr[rightchild]<arr[leftchild]){
//             minchild=rightchild;
//         }
//         if(arr[minchild]>=arr[crnt]){
//             return;
//         }
//         swap(arr[minchild],arr[crnt]);
//         crnt=minchild;
//     }
// }
// int main(){
//     int size;
//     cin>>size;
//     int arr[size];
//     for(int &i:arr) cin>>i;
//     for(int i=size/2;i>0;i--){
//         heapify(arr,size,i);
//     }
//     for(int i=1;i<size;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// return 0;
// }

// 2.MAX_HEAP


// #QUESTIONS

// 1.FIND   SUM BETWEEN Kth AND Lth SMALLEST ELEMENT OF AN ARRAY
// #include <bits/stdc++.h>
// using namespace std;
// void min_heapify(int arr[],int size,int crnt){
//     while(((crnt*2)+1)<size){
//         int l=(crnt*2)+1;
//         int r=(crnt*2)+2;
//         int m=l;
//         if(r<size and arr[r]<arr[l]) m=r;
//         if(arr[crnt]<arr[m])return;
//         swap(arr[m],arr[crnt]);
//         crnt=m;
//     }
// }
// void del(int arr[],int &size){
//     swap(arr[0],arr[--size]);
//     min_heapify(arr,size,0);
// }
// int sum(int arr[],int size,int k,int l){
//     for(int i=size/2;i>0;i--){
//         min_heapify(arr,size,i);
//     }
//     int cnt=0;
//     int add=0;
//     while(cnt<(l-1)){
//         del(arr,size);
//         cnt++;
//         if(cnt>(k-1) and cnt<(l-1)){
//             add+=arr[0];
//             cout<<arr[0]<<" ";
//         }
//     }
//     return add;
//     }
// int main(){
// int arr[7]={1,8,4,6,7,2,3};
// cout<<sum(arr,7,2,5);
// return 0;
// }