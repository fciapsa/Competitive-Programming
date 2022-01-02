#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T, c, n, k, sol;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> c >> n;
		std::vector<int> v(n);
		for (int j = 0; j < n; ++j) std::cin >> v[j];
		sort(v.begin(), v.end());

		k = 0;
		sol = 0;
		--c;
		while (k + c < n) {
			if (v[k + c] - v[k] <= 15) {
				++sol;
				k += c + 1;
			}
			else ++k;
		}
		std::cout << sol << '\n';
	}
return 0;
}