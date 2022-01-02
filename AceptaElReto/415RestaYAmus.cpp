#include <iostream>

int main() {
	int x;
	std::cin >> x;
	while (x != 0) {
		if (x % 9 == 0) std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> x;
	}

return 0;
}