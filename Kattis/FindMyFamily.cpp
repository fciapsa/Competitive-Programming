#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int k, n, ans = 0;
	vector<int> sol;
	cin >> k;
	for (int f = 1; f <= k; ++f) {
		cin >> n;
		vector<int> v(n), mx(n);
		for (int i = 0; i < n; ++i)cin >> v[i];
		mx[n - 1] = v[n - 1];
		for (int i = n - 2; i >= 0; --i) mx[i] = max(v[i], mx[i + 1]);

		bool found = false;
		set<int> s = { v[0] };
		for (int i = 1; i < n - 1 && !found; ++i) {
			auto it = s.upper_bound(v[i]);
			if (it != s.end() && mx[i + 1] > * it) {
				found = true;
				++ans;
				sol.push_back(f);
			}
				s.insert(v[i]);
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < ans; ++i) cout << sol[i] << '\n';

	return 0;
}