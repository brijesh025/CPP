#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
#define in(n) ll n; cin >> n;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fr(n) for (int i = 0; i < n; i++)
#define fri(a) for (int &i : a) cin >> i;
#define vout(a) for (auto i : a) cout<<i<<' '; cout<<endl;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
void solve(){
    in(n);in(q);
    string s;cin>>s;
    vector<int> a(q);fri(a);
    int cntB=0;
    for(char c:s) if(c=='B') cntB++;
    if(cntB==0){
        for(auto x:a) cout<<x<<"\n";
        return;
    }
    vector<pair<char,int>> ops;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            int cnt=1;
            while(i+1<n && s[i+1]=='A'){cnt++; i++;}
            ops.push_back({'A',cnt});
        } else ops.push_back({'B',1});
    }
    for(auto x:a){
        ll val=x;
        ll steps=0;
        while(val>0){
            for(auto &p:ops){
                if(p.first=='B'){
                    val >>= 1;
                    steps++;
                    if(val==0) break;
                } else {
                    int cnt = p.second;
                    ll take = min<ll>(val, cnt);
                    steps += take;
                    val -= take;
                    if(val==0) break;
                }
            }
        }
        cout<<steps<<"\n";
    }
}
int main(){
    fastio;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
