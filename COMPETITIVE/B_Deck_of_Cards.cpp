#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

string solve(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    if(k==n)return string(n,'-');
    ll cnt0=0,cnt1=0,cnt2=0;
    for(char c:s){
        if(c=='0')cnt0++;
        else if(c=='1')cnt1++;
        else cnt2++;
    }
    string ans(n,'+');
    for(int i=0;i<n;i++){
        if(i<cnt0+cnt2 or i>=n-cnt1-cnt2)ans[i]='?';
        if(i<cnt0 or i>=n-cnt1 or n==k)ans[i]='-';
    }
    return ans;
}

int main(){
    fastio;
    int t;cin>>t;
    while(t--)cout<<solve()<<endl;
}
