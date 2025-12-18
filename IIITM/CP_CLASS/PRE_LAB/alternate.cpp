#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(),a.end());
    vector<int> asc(a.begin(),a.end());
    vector<int> dsc(a.rbegin(),a.rend());
    int cnt=0;
    for(int i=0;i<=n/2;i++){
        if(cnt<n){cout<<dsc[i]<<" ";cnt++;}
        if(cnt<n){cout<<asc[i]<<" ";cnt++;}
        
    }    
    return 0;
}