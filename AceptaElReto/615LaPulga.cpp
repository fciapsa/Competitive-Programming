#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, f, t, tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> f >> t;
		cout << (t % (n + 1)) * f << '\n';
	}

	return 0;
}