#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct state {
	int deleg, pro, contra, undec, cost;
};

#define INF 1e9+1

int main() {
	std::ios::sync_with_stdio(false);
	int s, tot, ned, all = 0;
	cin >> s;
	vector<state> v(s);
	for (int i = 0; i < s; ++i) {
		cin >> v[i].deleg >> v[i].pro >> v[i].contra >> v[i].undec;
		all += v[i].deleg;

		tot = v[i].pro + v[i].contra + v[i].undec;
		ned = tot / 2 + 1;

		if (v[i].pro + v[i].undec >= ned) v[i].cost = max(0, ned - v[i].pro);
		else v[i].cost = INF;
	}

	ned = all / 2 + 1;
	vector<vector<ll>> dp(s + 1, vector<ll>(ned + 1));
	//for (int i = 0; i <= s; ++i) dp[i][0] = 0;
	for (int j = 1; j <= ned; ++j) dp[s][j] = INF;
	for (int i = s - 1; i >= 0; --i) {
		for (int j = 1; j <= ned; ++j) {
			dp[i][j] = min(dp[i + 1][j], v[i].cost + dp[i + 1][max(0, j - v[i].deleg)]);
		}
	}

	if (dp[0][ned] >= INF) cout << "impossible\n";
	else cout << dp[0][ned] << '\n';

	return 0;
}