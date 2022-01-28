#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, k, mn_good, i1, i2, mn_size, x, y, accum, in, out, start, parts;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		mn_good = (n + k) / 2;
		if ((n + k) % 2) ++mn_good;

		vector<int> v(n), count(n+1);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			++count[v[i]];
		}

		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; ++i) {
			if (count[i]) vp.push_back({ i,count[i] });
		}

		x = vp[0].first;
		y = vp[vp.size() - 1].first;
		mn_size = y - x + 1;
		accum = i1 = i2 = 0;
		while (i2 < vp.size()) {
			while (i2 < vp.size() && accum < mn_good) {
				accum += vp[i2].second;
				++i2;
			}

			if (accum >= mn_good) {
				if (vp[i2 - 1].first - vp[i1].first + 1 < mn_size) {
					x = vp[i1].first;
					y = vp[i2-1].first;
					mn_size = y - x + 1;
				}
				accum -= vp[i1].second;
				++i1;
			}
		}
		while (accum >= mn_good) {
			if (accum >= mn_good) {
				if (vp[i2 - 1].first - vp[i1].first + 1 < mn_size) {
					x = vp[i1].first;
					y = vp[i2 - 1].first;
					mn_size = y - x + 1;
				}
			}
			accum -= vp[i1].second;
			++i1;
		}

		//Now we know the whole array has at least k more elements inside [x,y] than outside of it
		cout << x << ' ' << y << '\n';
		in = out = start = parts = 0;
		for (int i = 0; i < n; ++i) {
			if (x <= v[i] && v[i] <= y) ++in;
			else ++out;

			if (in > out && parts < k - 1) {
				++parts;
				in = out = 0;
				cout << start + 1 << ' ' << i + 1 << '\n';
				start = i + 1;
			}
		}
		cout << start+1 << ' ' << n << '\n';
	}
	return 0;
}