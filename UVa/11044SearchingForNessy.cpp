#include <iostream>
#include <cmath>

int main() {
	int T;
	double n, m;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n >> m;
		std::cout << ((int)ceil((n - 2) / 3)) * ((int)ceil((m - 2) / 3)) << '\n';
	}
	return 0;
}