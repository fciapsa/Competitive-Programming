#include <iostream>

int main() {
	int t, n, cm, cj, d, k = 0;
	std::cin >> t;
	while (t--) {
		++k;
		std::cin >> n;
		cm = 0;
		cj = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> d;
			cm += ((d / 30) + 1) * 10;
			cj += ((d / 60) + 1) * 15;
		}

		std::cout << "Case " << k << ": ";
		if (cm == cj) std::cout << "Mile Juice " << cm << '\n';
		else if (cm < cj) std::cout << "Mile " << cm << '\n';
		else std::cout << "Juice " << cj << '\n';
	}
return 0;
}