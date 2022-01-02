#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int d1, d2;
		std::cin >> d1 >> d2;
		if (d1 <= d2) {
			std::cout << d1 + 1;
			for (int i = d1 + 2; i <= d2 + 1; ++i) {
				std::cout << ' ' << i;
			}
			std::cout << '\n';
		}
		else {
			std::cout << d2 + 1;
			for (int i = d2 + 2; i <= d1 + 1; ++i) {
				std::cout << ' ' << i;
			}
			std::cout << '\n';
		}
	}
return 0;
}