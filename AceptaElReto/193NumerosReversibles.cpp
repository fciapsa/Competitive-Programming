#include <iostream>

int main() {
	int n, aux, rev, pot;
	bool ok;
	std::cin >> n;
	while (n != 0) {
		if (n % 10 == 0) std::cout << "NO\n";
		else {
			aux = n / 10;
			pot = 1;
			while (aux > 0) {
				pot *= 10;
				aux /= 10;
			}

			aux = n;
			rev = 0;
			while (aux > 0) {
				rev += (aux % 10) * pot;
				aux /= 10;
				pot /= 10;
			}

			aux = n + rev;
			ok = true;
			while (ok && aux > 0) {
				ok = (aux % 10) % 2;
				aux /= 10;
			}

			if (ok) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> n;
	}
return 0;
}