#include <iostream>
#include <vector>
using tMatriz = std::vector<std::vector<char>>;

void leerMatriz(tMatriz &m) {
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m[0].size(); ++j) {
			std::cin >> m[i][j];
		}
	}
}

void mostrarMatriz(tMatriz const&m) {
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m[0].size(); ++j) {
			if (m[i][j] == '-' || m[i][j] == '*') std::cout << 'X';
			else if (m[i][j] == ' ') std::cout << '-';
			else std::cout << m[i][j];
		}
		std::cout << '\n';
	}
}

void descubrir(tMatriz &m, int f, int c, bool &b) {
	if (m[f - 1][c - 1] == '*') b = true;
	else if (m[f - 1][c - 1] == '-') {
		int bomb = 0;
		if (f - 2 >= 0 && c - 2 >= 0 && m[f - 2][c - 2] == '*') ++bomb;
		if (f - 2 >= 0 && m[f - 2][c - 1] == '*') ++bomb;
		if (f - 2 >= 0 && c < m[0].size() && m[f - 2][c] == '*') ++bomb;
		if (c < m[0].size() && m[f - 1][c] == '*') ++bomb;
		if (c < m[0].size() && f < m.size() && m[f][c] == '*') ++bomb;
		if (f < m.size() && m[f][c - 1] == '*') ++bomb;
		if (c - 2 >= 0 && f < m.size() && m[f][c - 2] == '*') ++bomb;
		if (c - 2 >= 0 && m[f - 1][c - 2] == '*') ++bomb;
		if (bomb != 0) m[f - 1][c - 1] = char(bomb) + '0';
		else {
			m[f - 1][c - 1] = ' ';
			if (f - 2 >= 0 && c - 2 >= 0) descubrir(m, f - 1, c - 1, b);
			if (f - 2 >= 0) descubrir(m, f - 1, c, b);
			if (f - 2 >= 0 && c < m[0].size()) descubrir(m, f - 1, c + 1, b);
			if (c < m[0].size()) descubrir(m, f, c + 1, b);
			if (c < m[0].size() && f < m.size()) descubrir(m, f + 1, c + 1, b);
			if (f < m.size()) descubrir(m, f + 1, c, b);
			if (c - 2 >= 0 && f < m.size()) descubrir(m, f + 1, c - 1, b);
			if (c - 2 >= 0) descubrir(m, f, c - 1, b);
		}
	}
}

bool resuelveCaso() {
	int F, C;
	std::cin >> F >> C;
	if (!std::cin) return false;

	tMatriz m(F, std::vector<char>(C));
	leerMatriz(m);
	bool b = false; int K;//num celdas a descubrir
	std::cin >> K;
	for (int i = 0; i < K; ++i) {
		int f, c;
		std::cin >> f >> c;
		descubrir(m, f, c, b);
	}
	if (b) std::cout << "GAME OVER\n";
	else mostrarMatriz(m);
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}