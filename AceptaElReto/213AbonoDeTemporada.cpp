#include <iostream>
#include <algorithm>

int main() {
	int t, p, d;
	std::cin >> t >> p >> d;
	while (t != 0) {
		std::cout << (t / p) * d + std::min(d,t % p) << '\n';
	std::cin >> t >> p >> d;
	}
return 0;
}