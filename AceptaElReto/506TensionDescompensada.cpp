#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int max, min; char c;
		std::cin >> max >> c >> min;
		if (max >= min) std::cout << "BIEN\n";
		else std::cout << "MAL\n";
	}
return 0;
}