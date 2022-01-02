#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>//pair
#include <climits>

struct boton {
	int f1, f2, c1, c2;
};

int main() {
	int f, c, n, sol, cont;
	std::string w;
	char prev;
	std::cin >> f >> c >> n;
	while (f != 0) {
		std::vector<std::string> teclado(f);
		std::cin.ignore();
		for (int i = 0; i < f; ++i) getline(std::cin, teclado[i]);

		//obtener los rectangulos que determinan cada boton
		std::unordered_map<char, boton> map;
		map[teclado[0][0]] = { 0,0,0,0 };
		for (int i = 1; i < c; ++i) {
			if (teclado[0][i] != teclado[0][i - 1]) {
				map[teclado[0][i]] = { 0,0,i,i };
			}
			else ++map[teclado[0][i]].c2;
		}

		for (int i = 1; i < f; ++i) {
			if (teclado[i][0] == teclado[i - 1][0]) ++map[teclado[i][0]].f2;
			else map[teclado[i][0]] = { i,i,0,0 };
			for (int j = 1; j < c; ++j) {
				if (teclado[i][j] == teclado[i - 1][j]) {
					if (j == map[teclado[i][j]].c1) {
						++map[teclado[i][j]].f2;
					}
				}
				else if (teclado[i][j] == teclado[i][j - 1]) {
					++map[teclado[i][j]].c2;
				}
				else map[teclado[i][j]] = { i,i,j,j };
			}
		}

		//crear la matriz de adyacencia del grafo
		std::unordered_map<char, int> c2i;
		cont = 0;
		for (auto it = map.begin(); it != map.end(); ++it, ++cont) c2i[it->first] = cont;
		std::vector<std::vector<int>> adyMat(map.size(),std::vector<int>(map.size(),INT_MAX));
		for (int i = 0; i < map.size(); ++i) adyMat[i][i] = 0;
		for (auto it = map.begin(); it != map.end(); ++it) {

			if (it->second.f1 != 0 || it->second.f2 != f-1) {
				//tecla encima
				if (it->second.f1 == 0) adyMat[c2i[it->first]][c2i[teclado[f - 1][it->second.c1]]] = 1;
				else adyMat[c2i[it->first]][c2i[teclado[it->second.f1 - 1][it->second.c1]]] = 1;
				//tecla debajo
				if (it->second.f2 == f - 1) adyMat[c2i[it->first]][c2i[teclado[0][it->second.c1]]] = 1;
				else adyMat[c2i[it->first]][c2i[teclado[it->second.f2 + 1][it->second.c1]]] = 1;
			}
			if (it->second.c1 != 0 || it->second.c2 != c - 1) {
				//tecla derecha
				if (it->second.c2 == c - 1) adyMat[c2i[it->first]][c2i[teclado[it->second.f1][0]]] = 1;
				else adyMat[c2i[it->first]][c2i[teclado[it->second.f1][it->second.c2 + 1]]] = 1;
				//tecla izquierda
				if (it->second.c1 == 0) adyMat[c2i[it->first]][c2i[teclado[it->second.f1][c - 1]]] = 1;
				else adyMat[c2i[it->first]][c2i[teclado[it->second.f1][it->second.c1 - 1]]] = 1;
			}

		}

		//floyd
		std::vector<std::vector<std::vector<int>>> dist(map.size(),
			std::vector<std::vector<int>>(map.size(), std::vector<int>(map.size()+1,INT_MAX)));
		//casos base
		for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map.size(); ++j) {
				dist[i][j][0] = adyMat[i][j];
			}
		}
		//dp
		for (int k = 1; k <= map.size(); ++k) {
			for (int i = 0; i < map.size(); ++i) {
				for (int j = 0; j < map.size(); ++j) {
					dist[i][j][k] = dist[i][j][k - 1];
					if (dist[i][k-1][k-1] != INT_MAX && dist[k-1][j][k-1] != INT_MAX &&
					    dist[i][k - 1][k - 1] + dist[k - 1][j][k - 1] < dist[i][j][k]) {
						    dist[i][j][k] = dist[i][k - 1][k - 1] + dist[k - 1][j][k - 1];
					}
				}
			}
		}


		//resolver los n casos del input con las distancias ya precalculadas
		for (int i = 0; i < n; ++i) {
			std::cin >> w;
			prev = teclado[0][0];
			sol = 0;
			for (int j = 0; j < w.size(); ++j) {
				sol += dist[c2i[prev]][c2i[w[j]]][map.size()];
				prev = w[j];
			}
			std::cout << sol << '\n';
		}
		std::cout << "---\n";
	std::cin >> f >> c >> n;
	}
return 0;
}