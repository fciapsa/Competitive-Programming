#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T, p, n, ini, surv, sol;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> p >> n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];

		ini = 0;
		surv = 0;
		sol = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] >= p) {
				++surv;
				while (surv > 5) {
					if (v[ini] >= p) --surv;
					++ini;
				}
			}

			sol = std::max(sol,i - ini + 1);
		}

		std::cout << sol << '\n';
	}
	return 0;
}