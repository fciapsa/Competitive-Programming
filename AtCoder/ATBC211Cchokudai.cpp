#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>

using namespace std;
#define ll long long

const ll MOD = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    string s1;
    cin >> s1;
    string s2 = "chokudai";
    int n = s1.length(), m = s2.length();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            else dp[i][j] = dp[i - 1][j];
        }
    }
    
    cout << dp[n][m] << '\n';

    return 0;
}