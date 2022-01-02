#include <iostream>

int main() {
	int T, a, b;
	char op;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> a >> op >> b;
		if (op == '+') a += b;
		else a -= b;
		std::cout << a;
		std::cin >> op;
		while (op != '.') {
			std::cin >> b;
			if (op == '+') a += b;
			else a -= b;
			std::cout << ", " << a;
			std::cin >> op;
		}
		std::cout << '\n';
	}

return 0;
}