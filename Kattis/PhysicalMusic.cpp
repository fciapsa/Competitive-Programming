#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, x, ans, ind;
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = 0;
		vector<int> v;
		vector<bool> seen(n + 1, false);
		ind = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			seen[x] = true;
			while (ind <= n && seen[ind]) ++ind;
			if (ind < x) {
				++ans;
				v.push_back(x);
			}
		}
		cout << ans << '\n';
		if (ans) {
			sort(v.begin(), v.end());
			for (int i = 0; i < ans; ++i) cout << v[i] << '\n';
		}
	}
		
	return 0;
}