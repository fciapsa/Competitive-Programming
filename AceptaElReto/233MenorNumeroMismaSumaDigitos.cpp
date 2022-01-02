#include <iostream>

int main() {
	int n, x;
	std::cin >> n;
	while (n != 0) {
		x = n % 9;
		if (x > 0) std::cout << x;
		x = n / 9;
		for (int i = 0; i < x; ++i) std::cout << '9';
		std::cout << '\n';

	std::cin >> n;
	}
return 0;
}