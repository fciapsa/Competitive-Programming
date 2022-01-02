#include <iostream>

const int MIN = 4050, MAX = 10800;

int main() {
	int T, m, c;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> m >> c;
		if (m >= c * MIN && m <= c * MAX) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}