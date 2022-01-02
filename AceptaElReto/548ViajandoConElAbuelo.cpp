#include <iostream>
#include <vector>

bool resuelve() {
	int t, p;
	std::cin >> t >> p;

	if (!std::cin) return false;

	int total = 0, max = 0;
	std::vector<int> tramos(t);
	for (int i = 0; i < t; ++i) {
		std::cin >> tramos[i];
		total += tramos[i];
		if (tramos[i] > max) max = tramos[i];
	}

	int act, paro, aux;
	while (max < total) {
		act = (total+max-1) / 2;

		paro = 0;
		aux = 0;
		for (int i = 0; i < t && paro <= p; ++i) {
			if (aux + tramos[i] > act) {
				++paro;
				aux = tramos[i];
			}
			else aux += tramos[i];
		}

		if (paro <= p) total = act;
		else max = act + 1;
	}

	std::cout << max << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}