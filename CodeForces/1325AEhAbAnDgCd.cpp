#include <iostream>

int main() {
	int T, x;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> x;
		std::cout << 1 << ' ' << x - 1 << '\n';
	}

return 0;
}