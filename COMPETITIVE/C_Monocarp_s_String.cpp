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
bool isPrime(int n) { if (n <= 1) return false; for (int i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
pair<long double, long double> getQuadraticRoots(long double a, long double b, long double c) {
    long double d = b * b - 4 * a * c;
    long double r1 = (-b + sqrt(d)) / (2 * a);
    long double r2 = (-b - sqrt(d)) / (2 * a);
    return {r1, r2};
}

bool chk_at_most(const vector<int> &diff,int m,int D){
    int n = (int)diff.size()-1;
    unordered_map<int,int> cnt;
    cnt.reserve(n*2);
    int left = 0;
    for(int j=1;j<=n;j++){
        cnt[diff[j-1]]++;
        while(left < j - m){
            auto it = cnt.find(diff[left]);
            if(it!=cnt.end()){
                if(--(it->second)==0) cnt.erase(it);
            }
            left++;
        }
        int need = diff[j] - D;
        if(cnt.find(need) != cnt.end()) return true;
    }
    return false;
}

ll solve() {
    in(n);
    string s;cin>>s;
    int cnta=count(all(s),'a');
    int cntb=count(all(s),'b');
    if(cnta==cntb) return 0;
    if(cnta==0 || cntb==0) return -1;
    int D = cnta - cntb;
    int nn = (int)n;
    vector<int> diff(nn+1,0);
    for(int i=1;i<=nn;i++) diff[i]=diff[i-1]+(s[i-1]=='a'?1:-1);
    int l = abs(D);
    int r = nn;
    int ans = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(chk_at_most(diff,m,D)){
            ans = m;
            r = m-1;
        } else l = m+1;
    }
    if(ans==-1) return -1;
    if(ans==nn) return -1;
    return ans;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
