#include <iostream>

int main() {
	int k, n, t;
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		std::cin >> n >> t;
		std::cout << t - n << '\n';
	}
return 0;
}