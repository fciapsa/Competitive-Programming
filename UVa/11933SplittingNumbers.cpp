#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, a, b, i, lsone;
	cin >> n;
	while (n) {
		i = a = b = 0;
		while (n) {
			lsone = n & (-n);
			if (i % 2) b |= lsone;
			else a |= lsone;
			n ^= lsone;
			++i;
		}
		cout << a << ' ' << b << '\n';
    cin >> n;
	}
	return 0;
}