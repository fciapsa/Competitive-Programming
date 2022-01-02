#include <iostream>

int main() {
	int T, a, b;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> a >> b;
		if (b == 0) std::cout << "DIV0\n";
		else if (a == 0) std::cout << "0 0\n";
		else if (a > 0 && b > 0) std::cout << a / b << ' ' << a % b << '\n';
		else if (a > 0) {
			b = -b;
			if(a >= b) std::cout << '-' << a / b << ' ' << a % b << '\n';
			else std::cout << "0 " << a % b << '\n';
		}
		else if (b > 0) {
			if ((-a) % b == 0) std::cout << '-' << (-a) / b << " 0\n";
			else std::cout << '-' << (-a) / b + 1 << ' ' << b - ((-a) % b) << '\n';
		}
		else {
			a = -a;
			b = -b;
			if (a % b == 0) std::cout << a / b << " 0\n";
			else std::cout << a / b + 1 << ' ' << b - (a % b) << '\n';
		}

	}
return 0;
}