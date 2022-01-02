#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main() {
	int t, n, sol;
	cin >> t;
	while (t--) {
		cin >> n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		sol = 0;
		for (int i = 1; i < n; ++i) {
			sol += (v[i] - v[i - 1] - 1);
		}

		cout << sol << '\n';
	}

return 0;
}