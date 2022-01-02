#include <iostream>

int main() {
	int t;
	long long int x, max, min, n_max, n_min;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> x;
		max = x;
		min = x;
		n_max = 1;
		n_min = 1;
		std::cin >> x;
		while (x != 0) {
			if (x > max) {
				max = x;
				n_max = 1;
			}
			else if (x == max) ++n_max;
			if (x < min) {
				min = x;
				n_min = 1;
			}
			else if (x == min) ++n_min;

			std::cin >> x;
		}
		std::cout << min << ' ' << n_min << ' ' << max << ' ' << n_max << '\n';
	}
return 0;
}