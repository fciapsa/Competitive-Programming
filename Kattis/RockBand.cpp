#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int m, s;
	cin >> m >> s;
	vector<vector<int>> prefs(m, vector<int>(s));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < s; ++j) cin >> prefs[i][j];

	unordered_set<int> conj;
	for(int j = 0; j < s; ++j){
		for (int i = 0; i < m; ++i) conj.insert(prefs[i][j]);
		if (conj.size() - 1 == j) break;
	}

	vector<int> ans;
	for (int x : conj) ans.push_back(x);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	cout << ans[0];
	for (int i = 1; i < ans.size(); ++i) cout << ' ' << ans[i];
	cout << '\n';

	return 0;
}