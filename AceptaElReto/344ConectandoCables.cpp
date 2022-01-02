#include <iostream>

int main() {
	int T, n, x1, x2;
	char c;
	std::cin >> T;
	for(int t = 0; t < T; ++t) {
		x1 = 0;
		x2 = 0;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			std::cin >> c;
			if (c == 'H') ++x1;
			else ++x2;
			std::cin >> c;
			if (c == 'H') ++x1;
			else ++x2;
		}

		if (x1 == x2) std::cout << "POSIBLE\n";
		else std::cout << "IMPOSIBLE\n";
	}

return 0;
}