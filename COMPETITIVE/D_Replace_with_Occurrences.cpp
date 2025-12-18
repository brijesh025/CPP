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
#define fr(n) for (int i = 0; i < n; i++)
#define fri(a) for (int &i : a) cin >> i;
#define vout(a) for (auto i : a) cout<<i<<' '; cout<<endl;
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
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> sorted_b(n);
    for (int i = 0; i < n; ++i) {
        cin >> sorted_b[i].first;
        sorted_b[i].second = i;
    }

    sort(sorted_b.begin(), sorted_b.end());

    bool possible = true;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && sorted_b[j].first == sorted_b[i].first) {
            j++;
        }
        int count = j - i;
        int k = sorted_b[i].first;
        if (count % k != 0) {
            possible = false;
            break;
        }
        i = j;
    }

    if (!possible) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    int val_counter = 1;
    i = 0;
    while (i < n) {
        int j = i;
        while (j < n && sorted_b[j].first == sorted_b[i].first) {
            j++;
        }
        int k = sorted_b[i].first;
        
        for (int group_start = i; group_start < j; group_start += k) {
            for (int l = 0; l < k; ++l) {
                int original_idx = sorted_b[group_start + l].second;
                a[original_idx] = val_counter;
            }
            val_counter++;
        }
        i = j;
    }

    for (int idx = 0; idx < n; ++idx) {
        cout << a[idx] << (idx == n - 1 ? "" : " ");
    }
    cout << endl;
}
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
       solve();
    }
    return 0;
}