#include <iostream>
#include <vector>
#include <algorithm>//min,max

//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : nelems(N), ncjtos(nelems), id(nelems, -1) {}

	// devuelve el número de conjuntos disjuntos
	int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	int buscar(int p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(int p, int q) {
		int i = buscar(p);
		int j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = i;
		}
		else {
			id[j] += id[i]; id[i] = j;
		}
		--ncjtos;
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

protected:
	int nelems;           // los elementos son 0 .. nelems-1
	int ncjtos;           // número de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};


struct coord {
	int x, y;
};

int main() {
	int N, M, K, n, ult, ind, cuadr, ini_i, ini_j, hasta_i, hasta_j, dif1, dif2;
	bool found;
	std::cin >> N;
	while (std::cin) {
		std::cin >> M >> K >> n;

		std::vector<std::vector<char>> mat(N + 1, std::vector<char>(M + 1, '.'));
		mat[0][0] = 'x';
		mat[N][M] = 'x';
		std::vector<coord> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i].x >> v[i].y;
		}

		cuadr = K * K;
		ConjuntosDisjuntos uf((N + 1)*(M + 1));
		ult = (N + 1) * (M + 1) - 1;
		ind = n - 1;
		found = false;
		while(ind >= 0 && !found) {
			ini_i = std::max(0, v[ind].x - K);
			ini_j = std::max(0, v[ind].y - K);
			hasta_i = std::min(N, v[ind].x + K);
			hasta_j = std::min(M, v[ind].y + K);

			for (int i = ini_i; i <= hasta_i; ++i) {
				for (int j = ini_j; j <= hasta_j; ++j) {
					if (mat[i][j] == 'x') {
						dif1 = v[ind].x - i;
						dif2 = v[ind].y - j;
						if (dif1 * dif1 + dif2 * dif2 <= cuadr) {
							uf.unir(i * (M + 1) + j, v[ind].x * (M + 1) + v[ind].y);
						}
					}		
				}
			}

			mat[v[ind].x][v[ind].y] = 'x';

			if (uf.buscar(0) != uf.buscar(ult)) --ind;
			else found = true;
		}

		if (found) std::cout << v[ind].x << ' ' << v[ind].y << '\n';
		else std::cout << "NUNCA SE PUDO\n";

	std::cin >> N;
	}
return 0;
}