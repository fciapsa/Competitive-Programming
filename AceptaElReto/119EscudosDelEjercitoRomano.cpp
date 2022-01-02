#include <iostream>
#include <cmath>

int main() {
	long long int n, sol, x;
	std::cin >> n;
	while (n != 0) {
		sol = 0;
		while (n > 0) {
			x = std::sqrt(n);
			sol += (x + 4) * x;
			n -= x * x;
		}
		std::cout << sol << '\n';

	std::cin >> n;
	}
return 0;
}