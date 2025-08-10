#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    for(int i=1;i<n;i++)a[i] += a[i-1];
    for(int i=0;i<n;i++)if(a[n-1]-a[i]==a[i-1]) {cout<<i;break;}
    return 0;
}