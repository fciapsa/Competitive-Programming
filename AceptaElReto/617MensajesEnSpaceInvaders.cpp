#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		n *= 3;
		vector<char> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		for (int i = 0; i < n; i += 3) cout << v[i];
		for (int i = 1; i < n; i += 3) cout << v[i];
		for (int i = 2; i < n; i += 3) cout << v[i];
		cout << '\n';
	}
	return 0;
}