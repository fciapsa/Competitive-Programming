#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, q, a;
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		unordered_set<int> x;
		while(n--){
			cin >> a;
			x.insert(a & 511);
		}

		vector<int> ans(230, -1);
		while (q--) {
			cin >> a;
			if (ans[a] == -1) {
				for (int k : x) {
					ans[a] = max(ans[a], a & k);
				}
			}
			cout << ans[a] << '\n';
		}
	}
	return 0;
}