 #include <bits/stdc++.h>
 using namespace std;
 int maxm(vector<int> arr){
    int m=INT16_MIN;
    for(int i=0;i<arr.size();i++) m=max(arr[i],m);
    return m;
 }
void count_sort(vector<int> &arr){
    int max_ele=maxm(arr);
    vector<int> freq(max_ele+1,0);
    vector<int> ans(arr.size());
    for(int i=0;i<arr.size();i++) freq[arr[i]]++;
    for(int i=1;i<=max_ele;i++) freq[i]+=freq[i-1];
    for(int i=arr.size()-1;i>=0;i--) ans[--freq[arr[i]]]=arr[i];
    for(int i=0;i<arr.size();i++) arr[i]=ans[i];
 }
 int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int &i:arr) cin>>i;
    count_sort(arr);
    for(int &i:arr) cout<<i<<" ";
 return 0;
 }