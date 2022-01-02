#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	ll s, g, mxs, mng, sols, solg;
	bool ok;
	cin >> s >> g;
	while (cin) {
		ok = false;
		mxs = 0;
		mng = 2e18;
		while (s != 0) {
			if (s >= mxs && g <= mng) {
				ok = true;
				sols = s;
				solg = g;
				if (s > mxs) mxs = s;
				if (g < mng) mng = g;
			}
			else if (s > mxs) {
				ok = false;
				mxs = s;
				if (g < mng) mng = g;
			}
			else if (g < mng) {
				ok = false;
				mng = g;
			}
			cin >> s >> g;
		}
		if (!ok) cout << "NO HAY MEJOR\n";
		else cout << sols << ' ' << solg << '\n';
		cin >> s >> g;
	}

	return 0;
}