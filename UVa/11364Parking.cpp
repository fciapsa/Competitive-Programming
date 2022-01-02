#include <iostream>

int main() {
	int T, n, x, max, min;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		min = 99;
		max = 0;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x < min) min = x;
			if (x > max) max = x;
		}
		std::cout << 2 * (max - min) << '\n';
	}
	return 0;
}