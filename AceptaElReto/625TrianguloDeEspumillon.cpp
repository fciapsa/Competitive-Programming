#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, mx;
	bool found;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		if (n < 3) cout << "NO HAY NINGUNO\n";
		else {
			sort(v.begin(), v.end());

			found = false;
			for (int i = n-1; i >= 2 && !found; --i) {
				if (v[i] < v[i - 1] + v[i - 2]) {
					found = true;
					mx = v[i] + v[i - 1] + v[i - 2];
				}
			}

			if (!found) cout << "NO HAY NINGUNO\n";
			else cout << mx << '\n';
		}
	}
	return 0;
}