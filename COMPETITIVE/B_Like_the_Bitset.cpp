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

ll solve() {
    in(n); in(k);
    string s; cin >> s;
    int cnt = 0, chk = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
            chk = max(chk, cnt);
        } else cnt = 0;
    }
    if (chk >= k) {
        cout << "NO"<<endl;
        return 0;
    }
    
    cout << "YES"<<endl;
    vector<int> perm(n);
    int num = 1;
    for (int i = 0; i < n;i++) if (s[i] =='1') perm[i]=num++;
            
    for (int i = 0;i<n;i++) if (s[i] == '0') perm[i] = num++;

    vout(perm);
    return 0;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
