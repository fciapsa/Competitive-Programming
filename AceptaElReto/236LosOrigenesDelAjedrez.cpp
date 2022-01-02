#include <iostream>

int main() {
	long long int x1, r, n, sol;
	std::cin >> x1 >> r >> n;
	while (x1 != 0 || r != 0 || n != 0) {
		sol = 0;
		for (int i = 0; i < n; ++i) {
			sol += x1;
			x1 *= r;
		}
		std::cout << sol << '\n';
	std::cin >> x1 >> r >> n;
	}
return 0;
}