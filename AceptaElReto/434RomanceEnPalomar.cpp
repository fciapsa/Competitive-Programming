#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int p, h;
		std::cin >> p >> h;
		if (h < p) std::cout << "PRINCIPIO\n";
		else std::cout << "ROMANCE\n";
	}

return 0;
}