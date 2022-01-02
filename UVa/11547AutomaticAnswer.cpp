#include <iostream>

int main() {
	int T, n;
	std::cin >> T;
	for(int t = 0;t < T; ++t){
		std::cin >> n;
		n = (((n * 63 + 7492) * 5 - 498) / 10) % 10;
		if (n < 0) std::cout << -n << '\n';
		else std::cout << n << '\n';
	}
	return 0;
}