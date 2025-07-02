#include <bits/stdc++.h>//simply deivde  the array in parts and keep maikng a 
using namespace std;//sorted array of that part and keep 
void merge(int arr[],int low,int mid,int high){//updating the actuall arary, devide by using index don't 
    int temp_arr[high-low+1];//do actuall devision of array
    int left=low;
    int right=mid+1;
    int crnt_ind=0;
    while(left<=mid and right<=high){
        if(arr[left]<=arr[right]) temp_arr[crnt_ind++]=arr[left++];
        else temp_arr[crnt_ind++]=arr[right++];
    }
    while(left<=mid) temp_arr[crnt_ind++]=arr[left++];
    while(right<=high) temp_arr[crnt_ind++]=arr[right++];
    for(int i=low;i<=high;i++) arr[i]=temp_arr[i-low];
}
void merge_sort(int arr[],int low,int high){//-->O(nlogn)
    int mid=(low+high)/2;
    if(low==high) return;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int &i:arr)cin>>i;
    merge_sort(arr,0,size-1);
    for(int &i:arr)cout<<i<<" ";
return 0;
}