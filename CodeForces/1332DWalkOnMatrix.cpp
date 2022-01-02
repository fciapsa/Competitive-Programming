#include <iostream>

const int POT = 131072, ALL1 = 262143;

int main() {
	int k;
	std::cin >> k;
	if (k == 0) std::cout << "1 1\n1\n";
	else {
		std::cout << "3 4\n";
		std::cout << ALL1 << ' ' << ALL1 << ' ' << POT << ' ' << POT << '\n';
		std::cout << POT << ' ' << k << ' ' << POT << ' ' << POT << '\n';
		std::cout << POT << ' ' << ALL1 << ' ' << ALL1 << ' ' << k << '\n';
	}
}