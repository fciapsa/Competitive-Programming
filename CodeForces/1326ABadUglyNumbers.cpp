#include <iostream>

int main() {
	long long int t, n;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		if (n == 1) std::cout << "-1\n";
		else {
			for (int i = 2; i < n; ++i) std::cout << '2';
			if (((n - 1) * 2 + 3) % 3 == 0) {
				std::cout << "33\n";
			}
			else std::cout << "23\n";
		}
	}
return 0;
}