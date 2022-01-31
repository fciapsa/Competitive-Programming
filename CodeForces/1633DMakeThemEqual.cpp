#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	vector<int> minOps(1001, 1e9);
	minOps[1] = 0;
	int x, q;
	for (int i = 1; i <= 1000; ++i) {
		x = 1;
		q = i;
		while (q > 0) {
			if (i + q <= 1000) minOps[i + q] = min(minOps[i + q], minOps[i] + 1);
			++x;
			q = i / x;
		}
	}

	int tc, n, k;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		vector<int> b(n), c(n);
		for (int i = 0; i < n; ++i) cin >> b[i];
		for (int i = 0; i < n; ++i) cin >> c[i];

		vector<vector<int>> dp(n + 1, vector<int>(12 * n + 1));
		if (b[n - 1] == 1) dp[n - 1][0] = c[n - 1];
		for (int i = n - 2; i >= 0; --i){
			if (b[i] == 1) dp[i][0] = c[i] + dp[i + 1][0];
			else dp[i][0] = dp[i + 1][0];
		}

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 1; j < dp[0].size(); ++j) {
				if (j < minOps[b[i]]) dp[i][j] = dp[i + 1][j];
				else dp[i][j] = max(dp[i + 1][j], c[i] + dp[i + 1][j - minOps[b[i]]]);
			}
		}

		cout << dp[0][min(k, (int)dp[0].size() - 1)] << '\n';
	}
	return 0;
}