#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, x, m;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		x = 0;
		for (int j = 0; j < n; ++j) {
			cin >> m;
			x |= m;
		}
		if (i > 0) cout << ' ';
		cout << x;
	}
	cout << '\n';
	return 0;
}