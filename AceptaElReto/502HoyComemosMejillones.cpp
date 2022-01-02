#include <iostream>
#include <vector>

bool buscarBin(std::vector<int> const& mont,int ini, int fin, int buscado, int &pos) {
	if (ini == fin - 1) {
		if (mont[ini] >= buscado) {
			pos = ini;
			return true;
		}
		else return false;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (mont[m] >= buscado) buscarBin(mont, ini, m + 1, buscado, pos);
		else buscarBin(mont, m + 1, fin, buscado, pos);
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<int> mont;

	int aux;
	std::cin >> aux;
	mont.push_back(aux);

	for (int i = 1; i < N; ++i) {
		int pos;
		std::cin >> aux;
		if (buscarBin(mont,0,mont.size(), aux + 1, pos)) {
			mont[pos] = aux;
		}
		else mont.push_back(aux);
	}

	std::cout << mont.size() << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}