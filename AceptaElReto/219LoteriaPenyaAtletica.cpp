#include <iostream>

int main() {
	int T, n, cont, x;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		cont = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x % 2 == 0) ++cont;
		}
		std::cout << cont << '\n';
	}
return 0;
}