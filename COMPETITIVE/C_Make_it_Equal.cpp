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
#define fr(i, n) for (int i = 0; i < n; i++)
#define fri(i, a) for (int &i : a) cin >> i;
//const
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
// Utility Functions
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
string solve() {
    in(n);in(k);vi a(n);vi b(n);
    fri(i,a);fri(i,b);
    bool sol=true;
    map<ll,ll> m;
    for(auto i:b)m[i%k]++;
    for(auto i:a){
        if(m[i%k]>0)m[i%k]--;
        else if(m[(abs(i-(i/k)*k)%k)]>0)m[(abs(i-k)%k)]--;
        else if(m[abs(i-ll(ceil((float)i/(float)k)*k))%k]>0)m[(abs(i-ll(ceil((float)i/(float)k)*k))%k)]--;
        else {
            sol =false;
            break;
        }
    }
    if (sol)return "YES";
    else return "NO";
}
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}