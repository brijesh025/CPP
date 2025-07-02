#include <bits/stdc++.h>
using namespace std;
 int maxm(vector<int> arr){
    int m=INT16_MIN;
    for(int i=0;i<arr.size();i++) m=max(arr[i],m);
    return m;
 }
 void count_sort(vector<int> &arr,int pos){
    vector <int> freq(10,0);
    vector <int> ans(arr.size());
    for(int i=0;i<arr.size();i++) freq[(arr[i]/pos)%10]++;
    for(int i=1;i<10;i++)freq[i]+=freq[i-1];
    for(int i=arr.size()-1;i>=0;i--) ans[--freq[(arr[i]/pos)%10]]=arr[i];
    for(int i=0;i<arr.size();i++)arr[i]=ans[i];
 }
void radix_sort(vector <int> &arr){
    for(int pos=1;maxm(arr)/pos>0;pos*=10){
        count_sort(arr,pos);
    }
}
int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int &i:arr)cin>>i;
    radix_sort(arr);
    for(int &i:arr)cout<<i<<" ";
return 0;
}