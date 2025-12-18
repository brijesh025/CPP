#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define in(n) ll n; cin >> n;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fri(a) for (int &i : a) cin >> i;

ll solve() {
    in (n); in (k);
    vi c(n); fri(c); 

    vector<vector<int>> pos(k+1);
    for(int i=0;i<n;i++) pos[c[i]].push_back(i+1);

    ll ans = n; 
    for(int col=1;col<=k;col++){
        if(pos[col].empty()) continue;

        vector<int> gaps;
        gaps.push_back(pos[col][0]-0); // from start to first
        for(int i=1;i<pos[col].size();i++)
            gaps.push_back(pos[col][i]-pos[col][i-1]);
        gaps.push_back((n+1) - pos[col].back()); // last to end

        sort(gaps.rbegin(), gaps.rend());
        int largest = gaps[0];
        int second = (gaps.size()>1 ? gaps[1] : 0);
        int effective = max((largest+1)/2, second);

        ans = min(ans,(ll)effective);
    }
    return ans-1;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}
