#include <iostream>

int main() {
	long long int T, n, t, m, d, i, sol, ndesc;
	std::cin >> T;
	for (int s = 0; s < T; ++s) {
		std::cin >> n >> t >> m >> d >> i;
		sol = n * t;
		if (n > m) {
			if (n % m == 0) ndesc = n / m - 1;
			else ndesc = n / m;
			sol += ((ndesc * (d + d + (ndesc - 1) * i)) / 2);
		}
		std::cout << sol << '\n';
	}
return 0;
}