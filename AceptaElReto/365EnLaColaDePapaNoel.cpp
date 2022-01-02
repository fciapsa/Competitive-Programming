#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T, n, a, k, aitor, sol;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> n >> a;
		--a;
		std::vector<int> v(n);
		for (int j = 0; j < n; ++j) std::cin >> v[j];
		aitor = v[a];
		k = 0;
		sol = 0;
		while (k < a) {
			sol += std::min(aitor, v[k]) * 2;
			++k;
		}
		sol += 2 * aitor;
		++k;
		--aitor;
		while (k < n) {
			sol += std::min(aitor, v[k]) * 2;
			++k;
		}
		std::cout << sol << '\n';
	}
return 0;
}