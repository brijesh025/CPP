#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
#define in(n) ll n; cin >> n;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fr(i, n) for (int i = 0; i < n; i++)
#define fri(i, a) for (int &i : a) cin >> i;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
bool compare(pii a, pii b) { if(a.s == b.s) return a.f > b.f; return a.s < b.s; }
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
pair<long double, long double> getQuadraticRoots(long double a, long double b, long double c) {
    long double discriminant = b * b - 4 * a * c;
    long double root1 = (-b + sqrt(discriminant)) / (2 * a);
    long double root2 = (-b - sqrt(discriminant)) / (2 * a);
    return {root1, root2};
}
ll solve() {
    in(n)
    vector<ll> ans;
    ll p=10;
    for(int k=1;k<=18;k++){
        ll d=1+p;
        if(d>n) break;
        if(n%d==0) ans.pb(n/d);
        if(p>LINF/10) break;
        p*=10;
    }
    if(ans.empty()) cout<<0<<"\n";
    else{
        sort(all(ans));
        cout<<ans.size()<<"\n";
        for(size_t i=0;i<ans.size();i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
