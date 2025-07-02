#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, max_sum = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < k; i++)max_sum+=arr[i];
    for(int i = k; i < n; i++){
        max_sum=max(max_sum,max_sum-arr[i-k]+arr[i]);
    }
    cout << max_sum << endl;
    
return 0;
}