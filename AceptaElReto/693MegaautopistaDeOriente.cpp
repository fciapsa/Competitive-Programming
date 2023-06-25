#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n;
    while (cin) {
        cin >> k;
        vector<int> pos(n), earn(n);
        for (int i = 0; i < n; ++i) cin >> pos[i];
        for (int i = 0; i < n; ++i) cin >> earn[i];

        vector<int> dp(n);
        dp[n - 1] = earn[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            auto next_it = lower_bound(pos.begin(), pos.end(),
                pos[i] + k);
            if (next_it != pos.end()) {
                int next_pos = next_it - pos.begin();
                dp[i] = max(dp[i + 1], earn[i] + dp[next_pos]);
            }
            else {
                dp[i] = max(earn[i], dp[i + 1]);
            }
        }

        cout << dp[0] << '\n';

        cin >> n;
    }

    return 0;
}