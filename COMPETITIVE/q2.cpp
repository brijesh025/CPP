#include <bits/stdc++.h>
using namespace std;

long long m_ini_l(const vector<long long>& a, int m, int n) {
    vector<long long> dp(n, (long long)4e18); // large sentinel

    auto A = [&](int i, int j) -> long long { return a[(long long)i * n + j]; };

    // Base: bottom-right cell
    dp[n - 1] = max(1LL, 1 - A(m - 1, n - 1));

    // Last row (i = m-1), j from n-2..0
    for (int j = n - 2; j >= 0; --j) {
        long long n_r = max(1LL, dp[j + 1] - A(m - 1, j));
        dp[j] = n_r;
    }

    // Remaining rows from bottom-2 up to top
    for (int i = m - 2; i >= 0; --i) {
        // Last column j = n-1
        dp[n - 1] = max(1LL, dp[n - 1] - A(i, n - 1));
        // Inner cells
        for (int j = n - 2; j >= 0; --j) {
            long long n_r = max(1LL, dp[j + 1] - A(i, j));
            long long n_d  = max(1LL, dp[j]     - A(i, j));
            dp[j] = min(n_r, n_d);
        }
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<long long> a;
    a.reserve(1LL * m * n);
    for (long long k = 0, tot = 1LL * m * n; k < tot; ++k) {
        long long x; cin >> x;
        a.push_back(x);
    }

    cout << m_ini_l(a, m, n);
    return 0;
}
