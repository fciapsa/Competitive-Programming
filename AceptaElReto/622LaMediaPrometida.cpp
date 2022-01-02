#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, sum, x, med;
	bool found;
	cin >> n;
	while (n != 0) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			sum += x;
		}
		cin >> med;
		med *= (n + 1);
		found = false;
		for (int i = 0; i <= 10 && !found; ++i) {
			if (sum + i == med) {
				found = true;
				x = i;
			}
		}

		if (!found) cout << "IMPOSIBLE\n";
		else cout << x << '\n';
		cin >> n;
	}
	return 0;
}