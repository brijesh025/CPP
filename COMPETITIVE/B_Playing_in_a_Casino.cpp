#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cards(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> cards[i][j];

        ll total = 0;
        for(int col = 0; col < m; col++) {
            vector<int> arr(n);
            for(int row = 0; row < n; row++)
                arr[row] = cards[row][col];

            sort(arr.begin(), arr.end());

            for(int j = 0; j < n; j++) {
                total += 1LL * arr[j] * (2 * j - n + 1);
            }
        }
        cout << total << "\n";
    }
}
