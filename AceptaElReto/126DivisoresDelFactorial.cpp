#include <iostream>

int main() {
	int p, n;
	std::cin >> p >> n;
	while (p > 0) {
		if (p <= n || p == 1) std::cout << "YES\n";
		else std::cout << "NO\n";
	std::cin >> p >> n;
	}
return 0;
}