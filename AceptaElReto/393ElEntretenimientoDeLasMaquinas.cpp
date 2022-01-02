#include <iostream>
#include <vector>
#include <string>

//N, NE, E, SE, S, SW, W, NW
const std::vector<int> vx = { -1,-1,0,1,1,1,0,-1 }, vy = { 0, 1, 1, 1, 0, -1, -1, -1 };
int C, F;

struct nodo {
	nodo(char c) : elem(c) {
		izq = nullptr;
		der = nullptr;
		cont = 0;
		fin = false;
	};
	char elem;
	nodo* izq;
	nodo* der;
	int cont;
	bool fin;
};

void insertar(std::string const& s, nodo*& act, int pos) {
	if (pos == s.size()) {
		act->fin = true;
		return;
	}

	if (s[pos] == '0') {
		if (act->izq == nullptr) act->izq = new nodo('0');
		insertar(s, act->izq, pos + 1);
	}
	else {
		if (act->der == nullptr) act->der = new nodo('1');
		insertar(s, act->der, pos + 1);
	}
}

void mostrar(nodo*& act, std::string s) {
	if (act->fin && act->cont) std::cout << s << ' ' << act->cont << '\n';

	if (act->izq != nullptr) mostrar(act->izq, s + '0');
	if (act->der != nullptr) mostrar(act->der, s + '1');
}

void buscar(std::vector<std::string> const& mat, nodo*& act, int x, int y, int dir) {
	if (x >= 0 && y >= 0 && x < F && y < C) {
		if (mat[x][y] == '0') {
			if (act->izq != nullptr) {
				if (act->izq->fin) ++act->izq->cont;
				buscar(mat, act->izq, x + vx[dir], y + vy[dir], dir);
			}
		}
		else {
			if (act->der != nullptr) {
				if (act->der->fin) ++act->der->cont;
				buscar(mat, act->der, x + vx[dir], y + vy[dir], dir);
			}
		}
	}
}

int main() {
	std::string s;
	int n, aux_i, aux_j;
	std::cin >> C >> F;
	while (std::cin) {
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) std::cin >> mat[i];

		nodo* raiz = new nodo('r');
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			std::cin >> s;
			insertar(s, raiz, 0);
		}


		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (mat[i][j] == '0') {
					if (raiz->izq != nullptr) {
						++raiz->izq->cont;
						for (int dir = 0; dir < 8; ++dir) {
							buscar(mat, raiz->izq, i + vx[dir], j + vy[dir], dir);
						}
					}
				}
				else {
					if (raiz->der != nullptr) {
						++raiz->der->cont;
						for (int dir = 0; dir < 8; ++dir) {
							buscar(mat, raiz->der, i + vx[dir], j + vy[dir], dir);
						}
					}
				}
			}
		}

		mostrar(raiz, "");

		std::cout << "---\n";
		std::cin >> C >> F;
	}
	return 0;
}