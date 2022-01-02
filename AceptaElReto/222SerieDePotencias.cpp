#include <iostream>

const int MOD = 1000007;

int main() {
	int x, n, sol, pot;
	std::cin >> x >> n;
	while (std::cin) {
		sol = 1;
		pot = 1;
		while (n > 0) {
			pot = (pot * x) % MOD;
			sol = (sol + pot) % MOD;
			--n;
		}
		std::cout << sol << '\n';
	std::cin >> x >> n;
	}
return 0;
}