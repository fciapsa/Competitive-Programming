#include <iostream>
#include <cmath>

int main() {
	long long int n, x, aux;
	bool found;
	std::cin >> x;
	while (std::cin) {
		x *= 2;
		found = false;
		for (long long int i = 1; !found; ++i) {
			aux = x + ((i - 1) * i);
			n = std::sqrt(aux);
			if (n * (n + 1) == aux) {
				found = true;
				n = n - i + 1;
			}
		}
		std::cout << n << '\n';
	std::cin >> x;
	}
return 0;
}