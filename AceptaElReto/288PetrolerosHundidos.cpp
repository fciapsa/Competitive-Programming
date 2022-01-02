#include <vector>
#include <iostream>
#include <string>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(long int N) : nelems(N), id(nelems, -1) {}

	// devuelve el número de conjuntos disjuntos
	//int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	long int buscar(long int p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	long int unir(long int p, long int q) {
		long int i = buscar(p);
		long int j = buscar(q);
		if (i == j) return -id[i];
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			//--ncjtos;
			return -id[i];
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			//--ncjtos;
			return -id[j];
		}
	}

	long int tam(long int p) const {
		return -id[buscar(p)];
	}

	bool unidos(long int p, long int q) const {
		return buscar(p) == buscar(q);
	}

protected:
	long int nelems;           // los elementos son 0 .. nelems-1
	//int ncjtos;           // número de conjuntos disjuntos
	mutable std::vector<long int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};

bool resuelveCaso() {
	long int F, C;
	std::cin >> F >> C;

	if (!std::cin) return false;

	std::cin.ignore();//ignorar el salto de linea tras C
	std::vector<std::string> mat(F);
	for (long int i = 0; i < F; ++i) {
		getline(std::cin, mat[i]);
	}

	ConjuntosDisjuntos conjs(F * C);
	long int max = 0, act, elem = 0;
	for (long int i = 0; i < F; ++i) {
		for (long int j = 0; j < C; ++j) {
			if (mat[i][j] == '#') {
				if (max < 1) max = 1;

				if (i > 0 && j < C - 1 && mat[i - 1][j + 1] == '#') {
					act = conjs.unir(elem, elem - C + 1);//diagonal arriba derecha
					if (act > max) max = act;
				}
				if (j < C - 1 && mat[i][j + 1] == '#') {
					act = conjs.unir(elem, elem + 1);//derecha
					if (act > max) max = act;
				}
				if (i < F - 1 && j < C - 1 && mat[i + 1][j + 1] == '#') {
					act = conjs.unir(elem, elem + C + 1);//diagonal abajo derecha
					if (act > max) max = act;
				}
				if (i < F - 1 && mat[i + 1][j] == '#') {
					act = conjs.unir(elem, elem + C);//abajo
					if (act > max) max = act;
				}
			}
			++elem;
		}
	}

	std::cout << max;
	if (max < 1) max = 1;

	long int N, x, y, nuevo;
	std::cin >> N;
	for (long int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		--x; --y;
		mat[x][y] = '#';
		nuevo = C * x + y;

		//realizar las nuevas uniones
		if (x > 0 && y < C - 1 && mat[x - 1][y + 1] == '#') {
			act = conjs.unir(nuevo, nuevo - C + 1);//diagonal arriba derecha
			if (act > max) max = act;
		}
		if (y < C - 1 && mat[x][y + 1] == '#') {
			act = conjs.unir(nuevo, nuevo + 1);//derecha
			if (act > max) max = act;
		}
		if (x < F - 1 && y < C - 1 && mat[x + 1][y + 1] == '#') {
			act = conjs.unir(nuevo, nuevo + C + 1);//diagonal abajo derecha
			if (act > max) max = act;
		}
		if (x < F - 1 && mat[x + 1][y] == '#') {
			act = conjs.unir(nuevo, nuevo + C);//abajo
			if (act > max) max = act;
		}
		if (x < F - 1 && y > 0 && mat[x + 1][y - 1] == '#') {
			act = conjs.unir(nuevo, nuevo + C - 1);//diagonal abajo izquierda
			if (act > max) max = act;
		}
		if (y > 0 && mat[x][y - 1] == '#') {
			act = conjs.unir(nuevo, nuevo - 1);//izquierda
			if (act > max) max = act;
		}
		if (y > 0 && x > 0 && mat[x - 1][y - 1] == '#') {
			act = conjs.unir(nuevo, nuevo - C - 1);//diagonal arriba izquierda
			if (act > max) max = act;
		}
		if (x > 0 && mat[x - 1][y] == '#') {
			act = conjs.unir(nuevo, nuevo - C);//arriba
			if (act > max) max = act;
		}
		std::cout << ' ' << max;
	}

	std::cout << '\n';
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
	return 0;
}