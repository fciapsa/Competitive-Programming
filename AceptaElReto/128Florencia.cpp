#include <iostream>
#include <algorithm>

int main() {
	int tam, nervios, segm, longi, cant, sol, retales, act, meDa;
	bool ok;
	std::cin >> tam;
	while (tam != -1) {
		sol = 0;
		retales = 0;
		ok = true;
		act = 0;
		std::cin >> nervios;
		while (nervios != -1) {
			std::cin >> segm >> longi;
			ok = ok && longi <= tam;
			if (ok) {
				cant = nervios * segm;
				while (cant > 0) {
					if (act >= longi) {
						meDa = act / longi;
						act -= std::min(cant, meDa) * longi;
						cant -= std::min(cant, meDa);
					}
					else {
						retales += act;
						act = tam;
						++sol;
					}
				}
			}
		std::cin >> nervios;
		}
		retales += act;

		if (ok) std::cout << sol << ' ' << retales << '\n';
		else std::cout << "IMPOSIBLE\n";


	std::cin >> tam;
	}
return 0;
}