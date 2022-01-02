#include <iostream>

int main() {
	int T, sol, acum, x;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		sol = 0;
		acum = 0;
		std::cin >> x;
		while (x != 0) {
			acum += 2*x;
			sol += acum;
		std::cin >> x;
		}
	std::cout << sol << '\n';
	}
return 0;
}