#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

int main() {
	int N, L, x, ant, importantes, ind, cont, aux, sol, min;
	std::cin >> N >> L;
	while (N != 0) {
		std::vector<std::vector<int>> data(L);
		std::vector<int> numL(N + 1);

		for (int i = 0; i < L; ++i) {
			std::cin >> x;
			while (x != 0) {
				++numL[x];
				data[i].push_back(x);
				std::cin >> x;
			}
		}

		std::unordered_map<int, int> map, rmap;//map: original->codificacion
		                                      //rmap: codificacion->original
		std::unordered_map<int, std::unordered_map<int,int>> adyList;
		importantes = 0;
		for (int i = 0; i < L; ++i) {
			ind = 0;
			while (ind < data[i].size() && numL[data[i][ind]] < 2) ++ind;

			if (ind < data[i].size()) {
				if (map.count(data[i][ind]) == 0) {
					++importantes;
					map[data[i][ind]] = importantes;
					rmap[importantes] = data[i][ind];
				}

				ant = map[data[i][ind]];
				++ind;
				cont = 1;
				while (ind < data[i].size()) {
					while (ind < data[i].size() && numL[data[i][ind]] < 2) {
						++ind;
						++cont;
					}

					if (ind < data[i].size()) {
						if (map.count(data[i][ind]) == 0) {
							++importantes;
							map[data[i][ind]] = importantes;
							rmap[importantes] = data[i][ind];
						}

						x = map[data[i][ind]];
						cont *= 10;
						//crear arista entre ant y x
						if (adyList[ant].count(x)) {
							if (cont < adyList[ant][x]) adyList[ant][x] = cont;
						}
						else adyList[ant][x] = cont;
						//la otra arista
						if (adyList[x].count(ant)) {
							if (cont < adyList[x][ant]) adyList[x][ant] = cont;
						}
						else adyList[x][ant] = cont;

						ant = x;
						++ind;
						cont = 1;
					}
				}
			}
		}

		std::vector<std::vector<int>> floyd(importantes + 1, std::vector<int>(importantes + 1, INT_MAX));
		for (int i = 1; i <= importantes; ++i) floyd[i][i] = 0;

		for (auto it1 = adyList.begin(); it1 != adyList.end(); ++it1) {
			for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
				floyd[it1->first][it2->first] = it2->second;
			}
		}

		for (int k = 1; k <= importantes; ++k) {
			for (int i = 1; i <= importantes; ++i) {
				for (int j = 1; j <= importantes; ++j) {
					if (floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX) {
						aux = floyd[i][k] + floyd[k][j];
						if (aux < floyd[i][j]) floyd[i][j] = aux;
					}
				}
			}
		}

		min = INT_MAX;
		for (int i = 1; i <= importantes; ++i) {
			aux = 0;
			for (int j = 1; j <= importantes; ++j) {
				aux += floyd[i][j];
			}

			if (aux < min) {
				min = aux;
				sol = rmap[i];
			}
			else if (aux == min) {
				if (rmap[i] < sol) sol = rmap[i];
			}
		}

		std::cout << sol << '\n';

		std::cin >> N >> L;
	}
return 0;
}