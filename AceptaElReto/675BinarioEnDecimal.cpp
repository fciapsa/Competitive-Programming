#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 10001

bool binDig(int x) {
    while (x && (x % 10 < 2)) x /= 10;
    return x == 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    vector<int> dp(MAXN + 1, 1e9);
    dp[0] = dp[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (binDig(i)) dp[i] = 0;
        else {
            //sumas
            for (int j = 1, k = i - 1; j <= k; ++j, --k) {
                dp[i] = min(dp[i], dp[j] + dp[k] + 1);
            }
            //productos
            for (int j = 2; j < i / 2; ++j) {
                if(i%j == 0) dp[i] = min(dp[i], dp[j] + dp[i/j] + 1);
            }
        }
    }

    int n;
    cin >> n;
    while(n) {
        cout << dp[n] << '\n';
        cin >> n;
    }

    return 0;
}