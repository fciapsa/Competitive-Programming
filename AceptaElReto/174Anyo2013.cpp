#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	int T, tam;
	std::string n, prim;
	bool hasRep, aux, keep;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		prim = n;
		tam = -1;

		std::unordered_map<char, int> map;
		hasRep = false;
		for (int i = 0; i < n.size(); ++i) {
			++map[n[i]];
			if (map[n[i]] > 1) hasRep = true;
		}

		//calculamos el limite inferior
		aux = hasRep;
		while ((hasRep && aux) || (!hasRep && !aux)) {
			++tam;
			keep = true;
			for (int i = prim.size() - 1; i >= 0 && keep; --i) {
				if (prim[i] == '0') {
					--map[prim[i]];
					prim[i] = '9';
					++map[prim[i]];
				}
				else {
					keep = false;
					--map[prim[i]];
					switch (prim[i]) {
					case '1': prim[i] = '0'; break;
					case '2': prim[i] = '1'; break;
					case '3': prim[i] = '2'; break;
					case '4': prim[i] = '3'; break;
					case '5': prim[i] = '4'; break;
					case '6': prim[i] = '5'; break;
					case '7': prim[i] = '6'; break;
					case '8': prim[i] = '7'; break;
					case '9': prim[i] = '8'; break;
					}
					++map[prim[i]];
				}
			}


			aux = false;
			for (auto it = map.begin(); it != map.end(); ++it) {
				if (it->second > 1) aux = true;
			}
		}
		//como siempre se resta uno de mas, rectificamos con +1
		keep = true;
		for (int i = prim.size() - 1; i >= 0 && keep; --i) {
			if (prim[i] == '9') prim[i] = '0';
			else {
				keep = false;
				switch (prim[i]) {
				case '0': prim[i] = '1'; break;
				case '1': prim[i] = '2'; break;
				case '2': prim[i] = '3'; break;
				case '3': prim[i] = '4'; break;
				case '4': prim[i] = '5'; break;
				case '5': prim[i] = '6'; break;
				case '6': prim[i] = '7'; break;
				case '7': prim[i] = '8'; break;
				case '8': prim[i] = '9'; break;
				}
			}
		}

		//retomamos desde n para calcular el limite superior
		map.clear();
		for (int i = 0; i < n.size(); ++i) {
			++map[n[i]];
		}

		aux = hasRep;
		while ((hasRep && aux) || (!hasRep && !aux)) {
			++tam;
			keep = true;
			for (int i = n.size() - 1; i >= 0 && keep; --i) {
				if (n[i] == '9') {
					--map[n[i]];
					n[i] = '0';
					++map[n[i]];
				}
				else {
					keep = false;
					--map[n[i]];
					switch (n[i]) {
					case '0': n[i] = '1'; break;
					case '1': n[i] = '2'; break;
					case '2': n[i] = '3'; break;
					case '3': n[i] = '4'; break;
					case '4': n[i] = '5'; break;
					case '5': n[i] = '6'; break;
					case '6': n[i] = '7'; break;
					case '7': n[i] = '8'; break;
					case '8': n[i] = '9'; break;
					}
					++map[n[i]];
				}
			}
			if (keep) {
				n = '1' + n;
				++map['1'];
			}

			aux = false;
			for (auto it = map.begin(); it != map.end(); ++it) {
				if (it->second > 1) aux = true;
			}
		}

		int k = 0;
		while (prim[k] == '0') ++k;
		while (k < prim.size()) {
			std::cout << prim[k];
			++k;
		}
		std::cout << ' ' << tam << '\n';

	}
return 0;
}