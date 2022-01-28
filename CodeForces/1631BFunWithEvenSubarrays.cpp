#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, obj, size, diff, ind, ans;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		ans = 0;
		obj = v[n - 1];
		size = 1;
		ind = n - 2;
		while (ind >= 0) {
			while (ind >= 0 && v[ind] == obj) {
				++size;
				--ind;
			}

			if (ind >= 0) {//v[ind] != obj
				++ans;
				ind -= size;
				size *= 2;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}