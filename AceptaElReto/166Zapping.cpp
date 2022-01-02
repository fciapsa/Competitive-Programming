#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
	int a, b;
	std::cin >> a >> b;
	while (a != 0) {
		std::cout << std::min(std::abs(a - b), 99 - std::max(a, b) + std::min(a, b)) << '\n';
	std::cin >> a >> b;
	}
return 0;
}