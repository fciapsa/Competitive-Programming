#include <iostream>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; ++i) std::cout << '1';
		std::cout << '\n';
		std::cin >> n;
	}
}