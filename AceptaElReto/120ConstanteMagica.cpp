#include <iostream>

int main() {
	long long int n, k, desp, sol;
	std::cin >> n >> k;
	while (n != 0) {
		if (n == 1) std::cout << k << '\n';
		else if (n == 3) std::cout << 3 * k + 12 << '\n';
		else {
			desp = ((n / 2) * (n / 2 + 1 + n / 2 + n / 2)) / 2 + ((n / 2) * (1 + n / 2)) / 2;
			k += desp;
			sol = 0;
			for (int i = 0; i < n; ++i) {
				sol += k;
				++k;
			}
			std::cout << sol << '\n';
		}
	std::cin >> n >> k;
	}
return 0;
}