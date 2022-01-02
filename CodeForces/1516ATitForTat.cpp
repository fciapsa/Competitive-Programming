#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc, n, k, ind;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		ind = 0;
		while (k > 0 && ind < n - 1) {
			while (k > 0 && v[ind] > 0) {
				--k;
				--v[ind];
				++v[n - 1];
			}
			++ind;
		}

		cout << v[0];
		for (int i = 1; i < n; ++i) cout << ' ' << v[i];
		cout << '\n';
	}
	return 0;
}