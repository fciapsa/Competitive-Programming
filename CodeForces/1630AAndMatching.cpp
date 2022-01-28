#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, k, ones;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		ones = n - 1;
		if (k == ones) {
			if(n==4) cout << "-1\n";
			else {
				int x1 = (ones >> 1);
				int x2 = (ones ^ x1);
				int x3 = x2 + 1;
				int x4 = (ones ^ x3);
				cout << n-1 << ' ' << x1 << '\n';
				cout << x2 << ' ' << x3 << '\n';
				cout << 0 << ' ' << x4 << '\n';
				for (int i = 1; i < n / 2; ++i) {
					if (i != x1 && i != x2 && i != x3 && i != x4)
						cout << i << ' ' << (i ^ ones) << '\n';
				}
			}
		}
		else {
			cout << n - 1 << ' ' << k << '\n';
			if(k != 0) cout << (k^ones) << ' ' << 0 << '\n';
			for (int i = 1; i < n/2; ++i) {
				if (i == k || i == (k^ones)) continue;
				cout << i << ' ' << (i^ones) << '\n';
			}
		}
	}
	return 0;
}