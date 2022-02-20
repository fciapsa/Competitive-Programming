#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	ll q, n, d;
	string f1, f2;
	cin >> q >> n >> d;
	cin >> f1 >> f2;
	vector<vector<ll>> dp(d + 1, vector<ll>(n + 1));
	//base cases
	dp[0][n] = 1;
	for (int i = 1; i <= d; ++i) dp[i][n] = 0;
	//first row
	for (int j = n - 1; j >= 0; --j) {
		if (f1[j] == f2[j]) dp[0][j] = dp[0][j + 1];
		else dp[0][j] = 0;
	}
	//recursive
	for (int i = 1; i <= d; ++i) {
		for (int j = n-1; j >= 0; --j) {
			if (f1[j] == f2[j]) {
				if (i > 1) dp[i][j] += (q - 1) * dp[i - 2][j + 1];
				dp[i][j] += dp[i][j + 1];
			}
			else {
				if (i > 1) dp[i][j] += (q - 2) * dp[i - 2][j + 1];
				dp[i][j] += 2 * dp[i - 1][j + 1];
			}
		}
	}
	cout << dp[d][0] << '\n';
	return 0;
}