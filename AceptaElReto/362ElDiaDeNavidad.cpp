#include <iostream>

int main() {
	int T, d, m;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> d >> m;
		if (d == 25 && m == 12) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}