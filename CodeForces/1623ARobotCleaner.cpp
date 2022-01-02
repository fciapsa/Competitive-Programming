#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	ll tc, n, m, rb, cb, rd, cd, sol1, sol2;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> rb >> cb >> rd >> cd;
		if (rb <= rd) sol1 = rd - rb;
		else sol1 = 2 * n - rb - rd;

		if (cb <= cd) sol2 = cd - cb;
		else sol2 = 2 * m - cb - cd;
		cout << min(sol1,sol2) << '\n';
	}
	return 0;
}