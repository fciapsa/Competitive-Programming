#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, a, b, sol, mn;
	cin >> n;

	vector<int> ca(101), cb(101), xca, xcb;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		++ca[a];
		++cb[b];
		sol = 0;
		xca = ca;
		xcb = cb;
		int i1 = 1, i2 = 100, k = 0;
		while (k <= i) {
			while (xca[i1] == 0) ++i1;
			while (xcb[i2] == 0) --i2;
			sol = max(sol, i1 + i2);
			mn = min(xca[i1], xcb[i2]);
			xca[i1] -= mn;
			xcb[i2] -= mn;
			k += mn;
		}
		cout << sol << '\n';
	}

	return 0;
}