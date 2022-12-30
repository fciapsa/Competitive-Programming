#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());
    int maxn = v[0] + v[1] + 1;

    vector<int> dp(maxn, 1e9);
    dp[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (int j = n - 1; j >= 0 && v[j] <= i; --j) {
            dp[i] = min(dp[i], 1 + dp[i - v[j]]);
        }
    }

    bool canon = true;
    vector<int> greedy(maxn);
    greedy[0] = 0;
    for (int i = 1; i < maxn && canon; ++i) {
        int coin = *lower_bound(v.begin(), v.end(), i, greater<int>());
        greedy[i] = 1 + greedy[i - coin];
        if (greedy[i] > dp[i]) canon = false;
    }
    if (canon) cout << "canonical\n";
    else cout << "non-canonical\n";

    return 0;
}