#include <iostream>

int main() {
	int T, a, b, c;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cin >> a >> b >> c;
		std::cout << "Case " << t << ": ";
		if (a > b) {
			if (a > c) {
				if (c > b) std::cout << c << '\n';
				else std::cout << b << '\n';
			}
			else std::cout << a << '\n';
		}
		else if (c > b) std::cout << b << '\n';
		else if (a < c) std::cout << c << '\n';
		else std::cout << a << '\n';
	}
return 0;
}