#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n % 2) cout << n - 1 << '\n';
		else cout << n + 1 << '\n';
	}
	return 0;
}