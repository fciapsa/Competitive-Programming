#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	long long int sol, h, aux;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> h;
		sol = 0;
		aux = 1;
		for (int i = h; i > 0; --i) {
			sol += i * aux;
			++aux;
		}

		std::cout << sol << '\n';
	}
	return 0;
}