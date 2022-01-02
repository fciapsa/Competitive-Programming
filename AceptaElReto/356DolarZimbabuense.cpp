#include <iostream>

int main() {
	int T;
	long long int a, b, c;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> a >> b >> c;
		if (a <= b) {
			if (a <= c) {
				if (b <= c) std::cout << a << ' ' << b << ' ' << c;
				else std::cout << a << ' ' << c << ' ' << b;
			}
			else std::cout << c << ' ' << a << ' ' << b;
		}
		else {
			if (b <= c) {
				if (a <= c) std::cout << b << ' ' << a << ' ' << c;
				else std::cout << b << ' ' << c << ' ' << a;
			}
			else std::cout << c << ' ' << b << ' ' << a;
		}

		std::cout << '\n';
	}

return 0;
}