#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> T(n);
    for (int i = 0; i < n; ++i) cin >> T[i];

    int m;
    cin >> m;
    vector<long long> s(m);
    for (int j = 0; j < m; ++j) cin >> s[j];

    sort(s.begin(), s.end());

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long t = T[i];
        // Find first sprinkler >= t
        auto it = lower_bound(s.begin(), s.end(), t);
        long long best = LLONG_MAX;

        if (it != s.end()) best = min(best, llabs(*it - t));
        if (it != s.begin()) {
            auto it2 = prev(it);
            best = min(best, llabs(*it2 - t));
        }

        // (m >= 1 by constraints, so best will be set)
        ans = max(ans, best);
    }

    cout << ans;
    return 0;
}
