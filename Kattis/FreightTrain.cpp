#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc, n, w, l, locoms, ind, act, sobra;
	cin >> tc;
	while (tc--) {
		cin >> n >> w >> l;

		vector<int> v(w);
		for (int i = 0; i < w; ++i) cin >> v[i];

		if (w == 1) {
			if (l == 1) cout << n << '\n';
			else if (l == 2) cout << min(v[0], n - v[0] + 1) << '\n';
			else cout << 1 << '\n';
		}
		else {
			int ini = 1, fin = n, m, ans = n;
			while (ini <= fin) {
				m = ini + (fin - ini) / 2;
				ind = locoms = 0;
				act = 1;
				while (ind < v.size() && locoms <= l) {
					if (v[ind] - act + 1 > m) {
						++locoms;
						act = v[ind];
					}
					while (ind < v.size() && v[ind] - act + 1 <= m) ++ind;

					sobra = m - (v[ind - 1] - act + 1);
					if (ind < v.size()) {
						act = v[ind - 1] + sobra + 1;
					}
					else if (n - v[ind - 1] > sobra) ++locoms;

					++locoms;
				}

				if (locoms <= l) {
					ans = m;
					fin = m - 1;
				}
				else ini = m + 1;
			}

			cout << ans << '\n';
		}
	}

return 0;
}