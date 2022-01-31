#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, n2;
	bool ok;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n % 7 == 0) cout << n << '\n';
		else {
			ok = false;
			n2 = n + 1;
			while (n2 % 10 && !ok) {
				if (n2 % 7 == 0) ok = true;
				else ++n2;
			}
			if (ok) cout << n2 << '\n';
			else {
				n2 = n - 1;
				while (!ok) {
					if (n2 % 7 == 0) ok = true;
					else --n2;
				}
				cout << n2 << '\n';
			}
		}
	}
	return 0;
}