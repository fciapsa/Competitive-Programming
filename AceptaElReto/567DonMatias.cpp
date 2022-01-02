#include <iostream>
#include <vector>
#include <map>
#include <stack>

/*
	El valor de un vertice lo podemos resolver o bien porque nos lo dan directamente o bien porque forma parte de
un ciclo de longitud impar.
	Una vez obtenido un valor, se puede resolver con ello el de todos los demas vertices de la misma componente conexa.
	Hay ciclos de longitud impar <=> El grafo no es bipartito
	Si el grafo es bipartito, lo unico que se puede obtener son las sumas de dos variables de distinto color
*/

int cont;

bool dfs(int act, std::vector<int>& comp_id, std::vector<char>& color, std::vector<int>& edgeTo, std::vector<int>& sum,
	std::vector<bool>& marked, std::vector<std::map<int, int>> const& adyList, std::vector<int>& valores) {
	bool bipartite = true;

	for (auto it = adyList[act].begin(); bipartite && it != adyList[act].end(); ++it) {
		if (!marked[it->first]) {
			marked[it->first] = true;
			comp_id[it->first] = cont;
			if (color[act] == '0') {
				color[it->first] = '1';
				sum[it->first] = sum[act] + it->second;
			}
			else {
				color[it->first] = '0';
				sum[it->first] = sum[act] - it->second;
			}
			edgeTo[it->first] = act;

			bipartite = dfs(it->first, comp_id, color, edgeTo, sum, marked, adyList, valores);
		}
		else if (color[act] == color[it->first]) {//ciclo de longitud impar detectado
			bipartite = false;

			int aux = it->second;
			for (int x = act, k = 0; x != it->first; x = edgeTo[x], ++k) {
				if ((k & 1) == 0) aux -= adyList[x].at(edgeTo[x]);
				else aux += adyList[x].at(edgeTo[x]);
			}
			valores[it->first] = aux / 2;
			//resolver toda la componente conexa
			std::vector<bool> visited(adyList.size(), false);
			visited[it->first] = true;
			std::stack<int> pila;
			pila.push(it->first);
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();

				for (auto cv : adyList[act]) {
					if (!visited[cv.first]) {
						visited[cv.first] = true;
						marked[cv.first] = true;
						valores[cv.first] = cv.second - valores[act];
						pila.push(cv.first);
					}
				}
			}
		}
	}

	return bipartite;
}

int main() {
	bool bipartite;
	int V, E, Q, a, b, d, act;
	char p;
	std::cin >> V >> E >> Q;
	while (V != 0) {
		std::vector<std::map<int, int>> adyList(V + 1);
		std::vector<int> valores(V + 1, -1);
		std::vector<int> directos;
		for (int i = 0; i < E; ++i) {
			std::cin >> p;
			if (p == '1') {
				std::cin >> a >> d;
				valores[a] = d;
				directos.push_back(a);
			}
			else {
				std::cin >> a >> b >> d;
				adyList[a][b] = d;
				adyList[b][a] = d;
			}
		}

		//resolver las componentes conexas de los valores recibidos en la entrada
		std::vector<bool> marked(V + 1, false);
		for (int i = 0; i < directos.size(); ++i) {
			if (!marked[directos[i]]) {
				act = directos[i];
				marked[act] = true;
				std::stack<int> dfs;
				dfs.push(act);
				while (!dfs.empty()) {
					act = dfs.top();
					dfs.pop();

					for (auto kv : adyList[act]) {
						if (!marked[kv.first]) {
							marked[kv.first] = true;
							valores[kv.first] = kv.second - valores[act];
							dfs.push(kv.first);
						}
					}
				}
			}
		}

		cont = 0;//id de componente conexa
		std::vector<int> comp_id(V + 1, -1);
		std::vector<char> color(V + 1);
		std::vector<int> edgeTo(V + 1, -1);
		std::vector<int> sum(V + 1);
		//en el resto de componentes conexas probar a bicolorear
		for (int i = 1; i <= V; ++i) {
			if (!marked[i]) {
				comp_id[i] = cont;
				color[i] = '0';
				sum[i] = 0;
				marked[i] = true;
				dfs(i, comp_id, color, edgeTo, sum, marked, adyList, valores);

				++cont;
			}
		}

		for (int i = 0; i < Q; ++i) {
			std::cin >> p;
			if (p == '1') {
				std::cin >> a;
				if (valores[a] != -1) std::cout << valores[a] << '\n';
				else std::cout << "CUIDADO\n";
			}
			else {
				std::cin >> a >> b;
				if (valores[a] != -1 && valores[b] != -1) std::cout << valores[a] + valores[b] << '\n';
				else if (valores[a] != -1 || valores[b] != -1) std::cout << "CUIDADO\n";
				else if (comp_id[a] == comp_id[b]) {
					if (color[a] == color[b]) std::cout << "CUIDADO\n";
					else {
						if (color[a] == '1') std::cout << sum[a] - sum[b] << '\n';
						else std::cout << sum[b] - sum[a] << '\n';
					}
				}
				else std::cout << "CUIDADO\n";
			}
		}

		std::cout << "---\n";
		std::cin >> V >> E >> Q;
	}
	return 0;
}