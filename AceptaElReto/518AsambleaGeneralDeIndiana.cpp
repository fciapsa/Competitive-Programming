#include <iostream>
#include <vector>

std::vector<int> v = { 0,31,28, 31,30,31,30,31,31,30,31,30,31 };

int main() {
	int x, y;
	char c;
	std::cin >> x >> c >> y;
	while (x != 0 || y != 0) {
		if (x > 0 && x <= 12 && y <= v[x] && y > 0) std::cout << "SI\n";
		else std::cout << "NO\n";

		std::cin >> x >> c >> y;
	}
	return 0;
}