#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>//min
#include <queue>
#include <functional>

std::vector<bool> marked(6);

struct nodo {
	int v, prio;
	bool operator>(nodo const& other) const {
		return prio > other.prio;
	}
};

void dijkstra(int s, std::vector<int>& distTo, std::vector<std::unordered_map<int, int>>& adyList) {
	nodo act;
	int v, aux;
	distTo[s] = 0;
	std::priority_queue<nodo, std::vector<nodo>, std::greater<nodo>> pq;
	pq.push({ s,0 });
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();

		v = act.v;
		if (act.prio > distTo[v]) continue;
		for (auto it = adyList[v].begin(); it != adyList[v].end(); ++it) {
			aux = distTo[v] + it->second;
			if (aux < distTo[it->first]) {
				distTo[it->first] = aux;
				pq.push({ it->first,aux });
			}
		}
	}
}

void probar(std::vector<int> const& pueblos, std::vector<std::vector<int>> const& distancias, int nivel, int ant, int first,
	int last, int solAct, int& solMejor) {

	if (nivel == 2) {
		int aux;
		for (int i = 0; i < pueblos.size(); ++i) {
			if (!marked[i]) {
				aux = distancias[first][pueblos[i]];
				if (aux < solMejor) {
					marked[i] = true;
					probar(pueblos, distancias, 3, pueblos[i], first, last, aux, solMejor);
					marked[i] = false;
				}
			}
		}
	}
	else if (nivel == pueblos.size()) {//solo queda poner el final
		solAct += distancias[last][ant];
		if (solAct < solMejor) solMejor = solAct;
	}
	else {//probar pasos intermedios
		int aux;
		for (int i = 0; i < pueblos.size(); ++i) {
			if (!marked[i]) {
				aux = solAct + distancias[i][ant];
				if (aux < solMejor) {
					marked[i] = true;
					probar(pueblos, distancias, nivel + 1, pueblos[i], first, last, aux, solMejor);
					marked[i] = false;
				}
			}
		}
	}
}

int main() {
	int np, nc, a, b, dist, C, aux, opt, idMejor, solMejor, num_asign;
	bool ok;
	std::cin >> np >> nc;
	while (std::cin) {
		std::vector<std::unordered_map<int, int>> adyList(np + 1);

		for (int i = 0; i < nc; ++i) {
			std::cin >> a >> b >> dist;
			if (a != b) {
				if (adyList[a].count(b)) {
					if (dist < adyList[a][b]) {
						adyList[a][b] = dist;
						adyList[b][a] = dist;
					}
				}
				else {
					adyList[a][b] = dist;
					adyList[b][a] = dist;
				}
			}
		}



		std::cin >> C;
		for (int c = 0; c < C; ++c) {
			std::cin >> num_asign;

			std::vector<int> pueblos(num_asign);
			std::vector<std::vector<int>> distancias(num_asign, std::vector<int>(np + 1, INT_MAX));
			for (int i = 0; i < num_asign; ++i) {
				std::cin >> pueblos[i];
				dijkstra(pueblos[i], distancias[i], adyList);
			}

			//precalcular el minimo coste de todos los posibles circuitos(identificados por su origen-fin)
			if (num_asign == 1) {
				solMejor = INT_MAX;
				idMejor = -1;
				for (int i = 1; i <= np; ++i) {
					if (i != pueblos[0] && distancias[0][i] != INT_MAX) {
						aux = 2 * distancias[0][i];
						if (aux < solMejor) {
							solMejor = aux;
							idMejor = i;
						}
					}
				}
			}
			else if (num_asign == 2) {
				solMejor = INT_MAX;
				idMejor = -1;
				for (int i = 1; i <= np; ++i) {
					if (i != pueblos[0] && i != pueblos[1] && distancias[0][i] != INT_MAX && distancias[1][i] != INT_MAX) {
						aux = distancias[0][i] + distancias[0][pueblos[1]] + distancias[1][i];
						if (aux < solMejor) {
							solMejor = aux;
							idMejor = i;
						}
					}
				}
			}
			else {
				std::vector<std::vector<int>> minCaminos(num_asign, std::vector<int>(num_asign, INT_MAX));
				for (int i = 0; i < num_asign; ++i) {
					for (int j = 0; j < num_asign; ++j) {
						if (i != j) {
							for (int k = 0; k < num_asign; ++k) marked[k] = false;
							marked[i] = true;
							marked[j] = true;
							solMejor = INT_MAX;
							probar(pueblos, distancias, 2, -1, i, j, 0, solMejor);
							minCaminos[i][j] = solMejor;
						}
					}
				}
				//calcular el resultado final probando el mejor pueblo de residencia
				solMejor = INT_MAX;
				idMejor = -1;
				for (int i = 1; i <= np; ++i) {
					ok = true;
					for (int j = 0; j < num_asign && ok; ++j) ok = i != pueblos[j];
					if (ok) {
						opt = INT_MAX;
						for (int x1 = 0; x1 < num_asign; ++x1) {
							for (int x2 = 0; x2 < num_asign; ++x2) {
								if (x1 != x2 && distancias[x1][i] != INT_MAX && distancias[x2][i] != INT_MAX) {
									aux = minCaminos[x1][x2] + distancias[x1][i] + distancias[x2][i];
									if (aux < opt) opt = aux;
								}
							}
						}
						if (opt < solMejor) {
							solMejor = opt;
							idMejor = i;
						}
					}
				}
			}

			std::cout << idMejor << ' ' << solMejor << '\n';
		}

		std::cout << "---\n";
		std::cin >> np >> nc;
	}
	return 0;
}