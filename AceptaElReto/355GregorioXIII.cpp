#include <iostream>

int main() {
	int n, t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		if (n % 100 == 0) {
			if (n % 400 == 0)std::cout << "29\n";
			else std::cout << "28\n";
		}
		else if (n % 4 == 0) std::cout << "29\n";
		else std::cout << "28\n";
	}
return 0;
}