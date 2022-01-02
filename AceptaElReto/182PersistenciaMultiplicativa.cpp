#include <iostream>

int main() {
	int T, n, sol, aux;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		sol = 0;
		while (n > 9) {
			++sol;
			aux = 1;
			while (n > 0) {
				aux *= (n % 10);
				n /= 10;
			}
			n = aux;
		}
		std::cout << sol << '\n';
	}
return 0;
}