#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, alcance, sol;
	cin >> n;
	while (n != 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		sol = 0;
		alcance = n - 1 - v[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (alcance <= i) ++sol;
			alcance = min(alcance, i - v[i]);
		}
		cout << sol << '\n';
		cin >> n;
	}
	return 0;
}