#include <iostream>

int main() {
	int n, m;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> m;
		switch (m) {
		case 0: std::cout << "1\n"; break;
		case 1: std::cout << "1\n"; break;
		case 2: std::cout << "2\n"; break;
		case 3: std::cout << "6\n"; break;
		case 4: std::cout << "4\n"; break;
		default: std::cout << "0\n";
		}
	}

return 0;
}