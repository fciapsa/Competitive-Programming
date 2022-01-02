#include <iostream>
#include <vector>

void sacarComp(std::vector<std::vector<int>> const& m, std::vector<int>& comp, int v, std::vector<bool>& visited) {
	comp.push_back(v);
	visited[v] = true;
	for (int i = 0; i < m[v].size(); ++i) {
		if (!visited[m[v][i]]) sacarComp(m, comp, m[v][i], visited);
	}
}

void colorear(std::vector<std::vector<int>> const& m, std::vector<int>& c, int v, bool& bp, std::vector<int> const& comp) {
	if (c[v] == 0) {
		c[v] = 1;

		for (int j = 0; j < m[v].size() && bp; ++j) {
			if (c[v] == c[m[v][j]]) bp = false;
			if (c[m[v][j]] == 0) {
				c[m[v][j]] = 2;
				colorear(m, c, m[v][j], bp, comp);
			}
		}
	}
	else {
		for (int j = 0; j < m[v].size() && bp; ++j) {
			if (c[v] == c[m[v][j]]) bp = false;
			else if (c[m[v][j]] == 0 && c[v] == 1) {
				c[m[v][j]] = 2;
				colorear(m, c, m[v][j], bp, comp);
			}
			else if (c[m[v][j]] == 0 && c[v] == 2) {
				c[m[v][j]] = 1;
				colorear(m, c, m[v][j], bp, comp);
			}
		}
	}
}

bool resuelve() {
	int V, A;
	std::cin >> V >> A;

	if (!std::cin) return false;

	std::vector<std::vector<int>> adyList(V);//Lista de adyacencia

	int a, b;
	for (int i = 0; i < A; ++i) {
		std::cin >> a >> b;
		adyList[a].push_back(b);
		adyList[b].push_back(a);
	}

	std::vector<bool> visited(V, false);
	std::vector<std::vector<int>> comps;
	for (int i = 0; i < V; ++i) {
		if (!visited[i]) {
			std::vector<int> comp;
			sacarComp(adyList, comp, i, visited);
			comps.push_back(comp);
		}
	}

	bool bp = true;
	std::vector<int> c(V, 0);//0 es sin pintar, 1 y 2 son los colores
	for (int i = 0; i < comps.size() && bp; ++i) {
		colorear(adyList, c, comps[i][0], bp, comps[i]);
	}

	if (bp) std::cout << "SI\n";
	else std::cout << "NO\n";
	return true;
}

int main() {
	while (resuelve());
	return 0;
}