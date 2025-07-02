#include <bits/stdc++.h>
using namespace std;
void max_heapify(int arr[],int size,int crnt){//TC-->O(n)
    while((crnt*2)<=size){
        int leftchild=(crnt*2);
        int rightchild=(crnt*2)+1;
        int maxchild=leftchild;
        if (rightchild<=size and arr[maxchild]<arr[rightchild]){
            maxchild=rightchild;
        }
        if(arr[maxchild]>arr[crnt]) {
            swap(arr[maxchild],arr[crnt]);
            crnt=maxchild;
            }
        else return;
    }
}
void del(int arr[],int &size){//TC-->O(logn)
    swap(arr[1],arr[size--]);
    max_heapify(arr,size,1);
}
void heap_sort(int arr[],int size){//TC-->O(nlogn)
    for(int i=size/2;i>0;i--){ //TC-->O(n) COMPLETE
        max_heapify(arr,size,i);
    }
    while(size>0){ //TC--> O(nlogn)
        del(arr,size);
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=1;i<=size;i++) cin>>arr[i]; 
    heap_sort(arr,size);
    for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
return 0;
}