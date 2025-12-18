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

ll mntn_d(ll r1, ll c1, ll r2, ll c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

ll che_d(ll r1, ll c1, ll r2, ll c2) {
    return max(abs(r1 - r2), abs(c1 - c2));
}


ll solve() {
    ll n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    vector<pair<ll, ll>> crnrs = {{0, 0}, {0, n}, {n, 0}, {n, n}};
    
    ll m_esct = -1;

    for (const auto& crnr : crnrs) {
        ll crnr_r = crnr.first;
        ll crnr_c = crnr.second;

        ll t_krug = mntn_d(rk, ck, crnr_r, crnr_c);
        ll t_doran = che_d(rd, cd, crnr_r, crnr_c);

        if (t_krug <= t_doran) {
            if (m_esct == -1 || t_doran > m_esct) {
                m_esct = t_doran;
            }
        }
    }

    if (m_esct != -1) {
        return m_esct;
    } else {
        ll dr = rk - rd;
        ll dc = ck - cd;
        ll k;

        ll k_row, k_col;
        
        if (dr > 0) k_row = n - rk;
        else k_row = rk;
        
        if (dc > 0) k_col = n - ck;
        else k_col = ck;

        if (abs(dr) > abs(dc)) {
            k = k_row;
        } else if (abs(dc) > abs(dr)) {
            k = k_col;
        } else {
            k = max(k_row, k_col);
        }
        
        return k + 1;
    }
}
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}
