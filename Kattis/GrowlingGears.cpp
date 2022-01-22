#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, sol;
	double a,b,c,best, x, fx;
	cin >> tc;
	while (tc--) {
		cin >> n;
		best = -DBL_MAX;
		for (int i = 1; i <= n; ++i) {
			cin >> a >> b >> c;
			x = (double)b / (2.0 * a);
			fx = -a * x * x + b * x + c;
			if (fx > best) {
				best = fx;
				sol = i;
			}
		}

		cout << sol << '\n';
	}
	return 0;
}