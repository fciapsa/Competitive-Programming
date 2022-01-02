#include <iostream>

int main() {
	long long int t, n, k;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> k;
		if (k%2 != n%2) std::cout << "NO\n";
		else {
			if (n < (k * (2 + (k - 1) * 2))/2) std::cout << "NO\n";
			else std::cout << "YES\n";
		}
	}
return 0;
}