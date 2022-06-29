#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tot, n;
    cin >> tot >> n;
    while (cin) {
        vector<int> pts(n);
        for (int i = 0; i < n; ++i) cin >> pts[i];

        vector<vector<int>> dp(tot + 1, vector<int>(n, -1));
        for (int j = 0; j < n; ++j) dp[0][j] = 0;
        for (int i = pts[0]; i <= tot; i += pts[0]) dp[i][0] = 1 + dp[i-pts[0]][0];

        for (int i = 1; i <= tot; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i >= pts[j]) {
                    if (dp[i - pts[j]][j] != -1 && dp[i][j - 1] != -1)
                        dp[i][j] = min(dp[i - pts[j]][j] + 1, dp[i][j - 1]);
                    else if (dp[i - pts[j]][j] != -1) dp[i][j] = dp[i - pts[j]][j] + 1;
                    else dp[i][j] = dp[i][j - 1];
                }
                else dp[i][j] = dp[i][j - 1];
            }
        }

        if (dp[tot][n - 1] == -1) cout << "Imposible\n";
        else {
            cout << dp[tot][n - 1] << ':';
            int i = tot, j = n - 1;
            while (i) {
                if (i < pts[j]) --j;
                else {
                    if (dp[i - pts[j]][j] == dp[i][j] - 1) {
                        cout << ' ' << pts[j];
                        i -= pts[j];
                    }
                    else --j;
                }
            }
            cout << '\n';
        }

    cin >> tot >> n;
    }

    return 0;
}