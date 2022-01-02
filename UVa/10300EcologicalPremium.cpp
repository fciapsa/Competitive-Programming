#include <iostream>

int main() {
	long long int t, a, b, c, f, sol;
	std::cin >> t;
	while (t--) {
		std::cin >> f;
		sol = 0;
		while (f--) {
			std::cin >> a >> b >> c;
			sol += a * c;
		}
		std::cout << sol << '\n';
	}
	return 0;
}