#include <iostream>
#include <vector>
#include <algorithm>

int busca(std::vector<int> const& v, int ini, int fin, int buscado) {
	if (ini >= fin) return -1;
	if (ini == fin - 1) {
		if (buscado >= v[ini]) return ini;
		return -1;
	}
	if (ini == fin - 2) {
		if (buscado >= v[fin - 1]) return fin - 1;
		if (buscado >= v[ini]) return ini;
		return -1;
	}
	
	int m = (ini + fin - 1) / 2;
	if (v[m] <= buscado) return busca(v, m, fin, buscado);
	else return busca(v, ini, m, buscado);
	
}

int main() {
	int n, pierde1, pierde2, ind;
	std::cin >> n;

	while (n != 0) {
		pierde1 = 0; pierde2 = 0;
		std::vector<int> d1(n);
		std::vector<int> d2(n);

		for (int i = 0; i < n; ++i) std::cin >> d1[i];
		for (int i = 0; i < n; ++i) std::cin >> d2[i];

		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());

		for (int i = 0; i < n; ++i) {
			ind = busca(d2, 0, n, d1[i]);
			pierde1 += (n - ind - 1);
			ind = busca(d1, 0, n, d2[i]);
			pierde2 += (n - ind - 1);
		}

		if (pierde1 < pierde2) std::cout << "PRIMERO\n";
		else if (pierde1 == pierde2) std::cout << "NO HAY DIFERENCIA\n";
		else std::cout << "SEGUNDO\n";

		std::cin >> n;
	}
	return 0;
}