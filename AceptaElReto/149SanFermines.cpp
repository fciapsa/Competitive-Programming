#include <iostream>

int main() {
	int n, x, max;
	std::cin >> n;
	while (std::cin) {
		std::cin >> max;
		for (int i = 1; i < n; ++i) {
			std::cin >> x;
			if (x > max) max = x;
		}
		std::cout << max << '\n';
	std::cin >> n;
	}
return 0;
}