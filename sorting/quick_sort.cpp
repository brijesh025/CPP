#include <bits/stdc++.h>//Smaller on the left and larger on the right, pick a pivot element and put it at correct positon,use two pointer
using namespace std;//take two pointer in left and right and swap element larger than pivot in right. 
int partition(int arr[],int low,int high){
    int pivot_ele=arr[low];
    int left=low+1;
    int right=high;
    while(left<=right){
        while(left<=high and arr[left]<=pivot_ele) left++;
        while(right>=low and arr[right]>pivot_ele) right--;
        if(left<right){
            swap(arr[left],arr[right]);
        }
    }
    swap(arr[low],arr[right]);
    return right;
}
void quick_sort(int arr[],int low,int high){// TC-->O(nlogn) OR O(n^2)
    if(low>=high) return;
    int pi=partition(arr,low,high);
    quick_sort(arr,low,pi-1);
    quick_sort(arr,pi+1,high);
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int &i:arr)cin>>i;
    quick_sort(arr,0,size-1);
    for(int &i:arr)cout<<i<<" ";
return 0;
}