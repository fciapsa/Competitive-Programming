#include <iostream>

int main() {
	int h, c;
	std::cin >> h >> c;
	while (c != 0) {
		if (h % c == 0) std::cout << h / c << "0\n";
		else std::cout << h / c + 1 << "0\n";
	std::cin >> h >> c;
	}
return 0;
}