#include <iostream>

int main() {
	int n, m, sol;
	std::cin >> n;
	while (n != 0) {
		sol = 1;
		m = 1;
		while (n % 2 == 0) {
			++m;
			n /= 2;
		}
		if (m > 1) sol *= m;
		for (int i = 3; i * i <= n; i += 2) {
			m = 1;
			while (n % i == 0) {
				++m;
				n /= i;
			}
			if (m > 1) sol *= m;
		}
		if (n > 1) sol *= 2;
		std::cout << sol << '\n';
		std::cin >> n;
	}
return 0;
}