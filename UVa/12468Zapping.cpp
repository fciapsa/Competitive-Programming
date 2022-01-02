#include <iostream>
#include <algorithm>

int main() {
	int a, b;
	std::cin >> a >> b;
	while (a != -1) {
		if (a < b) std::cout << std::min(b - a, a + 99 - b + 1) << '\n';
		else std::cout << std::min(a - b, 99 - a + 1 + b) << '\n';
	std::cin >> a >> b;
	}

return 0;
}