#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	int h, m;
	for (int i = 0; i < nc; ++i) {
		std::cin >> h;
		std::cin.get();
		std::cin >> m;
		
		if (m == 0) {
			if (h != 12) h = 12 - h;
		}
		else {
			if(h == 12) h = 11;
			else if(h == 11) h = 12;
			else h = 12 - h - 1;
			m = 60 - m;
		}

		if (h < 10) std::cout << '0';
		std::cout << h << ':';
		if (m < 10) std::cout << '0';
		std::cout << m << '\n';
	}

	return 0;
}