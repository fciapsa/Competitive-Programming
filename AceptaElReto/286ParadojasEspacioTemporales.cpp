#include <iostream>
#include <map>
#include <vector>

const std::vector<int> DIAS = { 0,0,31,59,90,120,151,181,212,243,273,304,334,365 };

int main() {
	int v, dd, mm, aa, c;
	char aux;
	std::cin >> v;
	while (v != 0) {
		std::map<int,int> llegadas, salidas;
		llegadas[12+DIAS[6]+1968*DIAS[13]] = 1;//nacimiento
		for (int i = 0; i < v; ++i) {
			std::cin >> dd >> aux >> mm >> aux >> aa;
			++salidas[dd + DIAS[mm] + aa * DIAS[13]];
			std::cin >> dd >> aux >> mm >> aux >> aa;
			++llegadas[dd + DIAS[mm] + aa * DIAS[13]];
		}

		int martys = 0;
		auto it1 = llegadas.begin(), it2 = salidas.begin();
		while (it1 != llegadas.end() && it2 != salidas.end()) {
			while (it1 != llegadas.end() && it1->first <= it2->first) {
				martys += it1->second;
				it1->second = martys;
				++it1;
			}
			if (it1 != llegadas.end()) {
				while (it2 != salidas.end() && it2->first < it1->first) {
					martys -= it2->second;
					if(llegadas.count(it2->first + 1) == 0) llegadas[it2->first + 1] += martys;
					++it2;
				}
			}
		}
		if (it1 != llegadas.end()) {
			while (it1 != llegadas.end()) {
				martys += it1->second;
				it1->second = martys;
				++it1;
			}
		}
		if (it2 != salidas.end()) {
			while (it2 != salidas.end()) {
				martys -= it2->second;
				llegadas[it2->first + 1] += martys;
				++it2;
			}
		}

		std::cin >> c;
		for (int i = 0; i < c; ++i) {
			std::cin >> dd >> aux >> mm >> aux >> aa;
			auto it = llegadas.lower_bound(dd + DIAS[mm] + aa * DIAS[13]);
			if (it == llegadas.end()) std::cout << llegadas.rbegin()->second << '\n';
			else if (it->first == dd + DIAS[mm] + aa * DIAS[13]) std::cout << it->second << '\n';
			else {
				if (it == llegadas.begin()) std::cout << "0\n";
				else {
					--it;
					std::cout << it->second << '\n';
				}
			}
		}

	std::cout << "----\n";
	std::cin >> v;
	}
return 0;
}