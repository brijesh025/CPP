/*
The prefix sum algorithm is used when you need to perform multiple queries about the 
sum of elements in a subarray of an array efficiently. 
Instead of recalculating the sum every time for each query, you can use the 
prefix sum technique to precompute sums, making the queries much faster.
1. Range Sum Queries
2. Subarray Sum Problems
3. Cumulative Frequency
4. 2D Prefix Sum (Matrix)
5. Handling Multiple Queries Efficiently
******For inclusive sum of given index elemetns, push 0 at the start and take arr[l]+arr[r+1]*****
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int &i:arr)cin>>i;
    for(int i=1;i<size;i++){
        arr[i]+=arr[i-1];
    }
    for(int &i:arr)cout<<i<<" ";
return 0;
}