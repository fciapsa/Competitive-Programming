#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, caso = 1, n, k;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cout << "Case #" << caso++ << ": ";
		if ((k % (1 << n)) == (1 << n) - 1) cout << "ON\n";
		else cout << "OFF\n";
	}
	return 0;
}