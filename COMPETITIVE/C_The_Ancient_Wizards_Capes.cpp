#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
//defines
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
//const
const int UNUSED_MOD = 1e9 + 7;
const ll LINF = 1e18;
const ll MODV = 676767677;
// Utility Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(a, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void solve(){
    ll n;cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    ll q=0;
    vector<ll> c(n+1,0);
    for(int i=1;i<=n;i++){
        c[i]=i - a[i] - 2*q;
        q+=c[i];
    }
    vector<ll> cand;
    for(int i=1;i<=n;i++){
        ll x1,x2;
        if(i%2==1){
            x1 = -c[i];
            x2 = 1 - c[i];
        } else {
            x1 = c[i];
            x2 = c[i]-1;
        }
        vector<ll> alwd;
        if(0<=x1 && x1<=n) alwd.push_back(x1);
        if(0<=x2 && x2<=n && x2!=x1) alwd.push_back(x2);
        if(i==1){
            cand = alwd;
            if(cand.empty()){ cout<<0<<'\n'; return;}
        } else {
            vector<ll> nc;
            for(ll v:cand){
                if(find(alwd.begin(),alwd.end(),v)!=alwd.end()) nc.push_back(v);
            }
            cand.swap(nc);
            if(cand.empty()){ cout<<0<<'\n'; return;}
        }
    }
    ll ans=0;
    if(n%2==1){
        if(q!=0){ cout<<0<<'\n'; return;}
        ans = cand.size();
    } else {
        if(0<=q && q<=n && find(cand.begin(),cand.end(),q)!=cand.end()) ans=1;
        else ans=0;
    }
    cout<< (ans%MODV) << '\n';
}
int main(){
    fastio;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
