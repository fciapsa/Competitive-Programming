#include <iostream>

int main() {
	int t, n, x, sol, k = 0;
	std::cin >> t;
	while (t--) {
		++k;
		std::cin >> n;
		sol = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x > sol) sol = x;
		}

		std::cout << "Case " << k << ": " << sol << '\n';
	}
return 0;
}