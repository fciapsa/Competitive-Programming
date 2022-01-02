#include <iostream>

int main() {
	int T, n, m;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n >> m;
		std::cout << 'W';
		for (int j = 1; j < m; ++j) std::cout << 'B';
		std::cout << '\n';
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << 'B';
			}
			std::cout << '\n';
		}
	}
return 0;
}