#include <iostream>

int cuatros(int x) {
	if (x < 5) {
		if (x == 4) return 1;
		return 0;
	}
	int resto = x % 5;
	int cont = cuatros(x / 5);
	
	if (resto == 4) return cont + 1;
	return cont;
}

int main() {
	int T, x;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> x;
		if (cuatros(x) > 1) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}