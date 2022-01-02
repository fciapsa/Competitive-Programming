#include <iostream>
#include <vector>

void conjuntos(std::vector<int> const& uvas, int max, int &act, int &comidas, int &cont, int k) {
	if (act + uvas[k] <= max) {
		act += uvas[k];
		++comidas;

		if (comidas < 12 && k+1 < uvas.size()) conjuntos(uvas, max, act, comidas, cont, k + 1);
		else if(comidas == 12) ++cont;

		act -= uvas[k];
		--comidas;
	}

	if(k+1 < uvas.size()) conjuntos(uvas, max, act, comidas, cont, k + 1);

}

bool resuelve() {
	int max, n;
	std::cin >> max >> n;

	if (max == 0 && n == 0) return false;

	std::vector<int> uvas(n);
	for (int i = 0; i < n; ++i) std::cin >> uvas[i];


	int cont = 0, comidas = 0, k = 0, act = 0;
	conjuntos(uvas, max, act, comidas, cont,k);

	std::cout << cont << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}