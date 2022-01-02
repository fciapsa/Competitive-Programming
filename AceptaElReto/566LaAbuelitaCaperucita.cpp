#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <climits>

/*Problema conocido: min-cut
Como las trampas se colocan en los vertices, para aplicar el algoritmo de max-flow debemos
desdoblar cada vertice en 2 para poner una arista entre ellos de capacidad 1(la trampa). El resto capacidad INF
El grafo resultante es dirigido, las aristas salen del segundo vertice de una casilla y llegan al
primer vertice de otra casilla
*/

int lobo, cap;
struct nodo {
	int pos, nivel;
};

int main() {
	bool found;
	int F, C, dc, T, dest, mf, v;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> F >> C;
		dc = 2 * C;

		std::vector<char> mat(F * dc);
		std::vector<std::map<int, int>> adyList(mat.size());//<destino,capacidad>
		for (int i1 = 0, i2 = 1; i1 < mat.size(); i1 += 2, i2 += 2) {
			std::cin >> mat[i1];
			mat[i2] = mat[i1];

			if (mat[i2] != '#') {
				adyList[i1][i2] = 1;

				if (i2 >= dc) {
					dest = i2 - dc - 1;
					if (mat[dest] != '#') {
						adyList[i2][dest] = INT_MAX;
						adyList[dest + 1][i1] = INT_MAX;
					}
				}
				if (i1 % dc > 0) {
					dest = i2 - 3;
					if (mat[dest] != '#') {
						adyList[i2][dest] = INT_MAX;
						adyList[dest + 1][i1] = INT_MAX;
					}
				}
			}

			if (mat[i2] == 'L') {
				lobo = i2;
				adyList[i1][i2] = INT_MAX;
			}
			else if (mat[i2] == 'C') {
				cap = i2;
				adyList[i1][i2] = INT_MAX;
			}
		}
		//no permitir que se coloquen trampas en las casillas adyacentes a caperucita
		//abajo
		if (cap > dc) {
			dest = cap - dc - 1;
			if (mat[dest] == '.') adyList[dest][dest + 1] = INT_MAX;
		}
		//izquierda
		if (cap % dc > 1) {
			dest = cap - 3;
			if (mat[dest] == '.') adyList[dest][dest + 1] = INT_MAX;
		}
		//derecha
		if (cap % dc < dc - 2) {
			dest = cap + 1;
			if (mat[dest] == '.') adyList[dest][dest + 1] = INT_MAX;
		}
		//arriba
		if (cap < mat.size() - dc) {
			dest = cap + dc - 1;
			if (mat[dest] == '.') adyList[dest][dest + 1] = INT_MAX;
		}

		//comprobar que no es imposible haciendo cuatro pasos de BFS desde la posicion de caperucita
		nodo act = { cap,0 };
		std::queue<nodo> q;
		q.push(act);
		found = false;
		while (!q.empty() && !found) {
			act = q.front();
			q.pop();

			for (auto kv : adyList[act.pos]) {
				if (kv.first == lobo) found = true;
				else if (act.nivel <= 2) q.push({ kv.first, act.nivel + 1 });
			}
		}

		if (found) std::cout << "IMPOSIBLE\n";
		else {
			//Ford-Fulkerson
			mf = 0;
			while (1) {
				found = false;
				std::vector<bool> marked(mat.size(), false);
				std::vector<int> edgeTo(mat.size(), -1);
				marked[lobo] = true;
				std::stack<int> dfs;
				dfs.push(lobo);
				while (!found && !dfs.empty()) {
					v = dfs.top();
					dfs.pop();

					for (auto kv : adyList[v]) {
						if (kv.first == cap) {
							found = true;
							edgeTo[cap] = v;
						}
						else if (!marked[kv.first]) {
							marked[kv.first] = true;
							edgeTo[kv.first] = v;
							dfs.push(kv.first);
						}
					}
				}

				if (!found) break;
				else {
					++mf;
					dest = cap;
					while (dest != lobo) {
						v = edgeTo[dest];
						--adyList[v][dest];
						if (adyList[v][dest] == 0) adyList[v].erase(dest);
						++adyList[dest][v];

						dest = v;
					}
				}
			}

			std::cout << mf << '\n';
		}
	}
	return 0;
}