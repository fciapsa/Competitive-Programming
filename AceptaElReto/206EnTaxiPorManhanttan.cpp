#include <iostream>
#include <cmath>

int main() {
	int T, n, x1, x2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		x1 = n - 1;
		n *= n;
		x2 = std::sqrt(n - x1 * x1);
		while (x1 * x1 + x2 * x2 != n) {
			--x1;
			x2 = std::sqrt(n - x1 * x1);
		}
		std::cout << x1 + x2 << '\n';
	}
return 0;
}