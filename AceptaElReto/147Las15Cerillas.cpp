#include <iostream>

// Por induccion se prueba que la unica posicion perdedora es que al que le toque el turno tenga k*max + k + 1 cerillas
// k = 0,...

int main() {
	int n, max, mod;
	std::cin >> n >> max;
	while (std::cin) {
		mod = n % (max + 1);
		if (mod == 1) std::cout << "PIERDO\n";
		else if (mod == 0) std::cout << max << '\n';
		else std::cout << mod - 1 << '\n';
	std::cin >> n >> max;
	}
return 0;
}