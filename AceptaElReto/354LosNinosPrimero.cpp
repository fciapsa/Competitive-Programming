#include <iostream>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {

		int x, max = 0, ninos = 0, altNino = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x > max) max = x;
			if (x <= altNino || i == 0) {
				ninos = i + 1;
				altNino = max;
			}
		}
		std::cout << ninos << '\n';
		std::cin >> n;
	}
return 0;
}