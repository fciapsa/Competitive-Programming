#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	while (a >= 0 && b >= 0) {
		std::cout << 2 * a + 2 * b << '\n';
		std::cin >> a >> b;
	}
	return 0;
}
