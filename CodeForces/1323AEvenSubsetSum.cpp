#include <iostream>

int main() {
	int t, n, aux, odd;
	bool even;
	int even1, odd1, odd2;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		even = false;
		odd = 0;
		for (int j = 0; j < n; ++j) {
			std::cin >> aux;
			if (!even && aux % 2 == 0) {
				even = true;
				even1 = j;
			}
			else if (odd<2 && aux % 2 == 1) {
				++odd;
				if (odd == 1) odd1 = j;
				else odd2 = j;
			}
		}
		if (even) {
			std::cout << "1\n";
			std::cout << even1+1 << '\n';
		}
		else if (odd == 2) {
			std::cout << "2\n";
			std::cout << odd1+1 << ' ' << odd2+1 << '\n';
		}
		else std::cout << "-1\n";
	}
return 0;
}