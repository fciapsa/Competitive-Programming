#include <iostream>
#include <vector>
#include <algorithm>//min

const int INF = 1000001;

/* Los cuatro problemas tienen un coste en tiempo en O(N*L) y en O(L) en espacio tras la optimizacion
al reducirlo a un solo vector en el que se sobreescribe(no necesitamos en ningun caso reconstruir la solucion)
*/

/* Nos piden esPosible(N,L) si tenemos la funcion:
esPosible(i,j) = booleano que indica si es posible conseguir una cuerda de longitud j considerando solo las varillas
				 de 1 a i

esPosible(i,j) = esPosible(i-1,j-l_i) || esPosible(i-1,j) si  l_i <= j
				 esPosible(i-1,j)                         si l_i > j
para 1 <= i <= N, 1 <= j <= L

CASOS BASE: esPosible(i,0) = true  si 0 <= i <= N
			esPosible(0,j) = false si 1 <= j <= L
*/

bool esPosiblePD(std::vector<int> const& l, int L) {
	//casos base
	std::vector<bool> esPosible(L + 1, false);
	esPosible[0] = true;

	//llevamos a cabo los casos recursivos sobreescribiendo el vector de derecha a izquierda
	for (int i = l.size() - 1; i >= 0; --i) {
		for (int j = L; j > 0; --j) {
			if (l[i] <= j) esPosible[j] = esPosible[j] || esPosible[j - l[i]];
			//en caso contrario el valor no varia
		}
	}

return esPosible[L];
}

/* Nos piden maneras(N,L) si tenemos la funcion:
maneras(i,j) = numero de maneras de obtener una cuerda de longitud j si solo consideramos las cuerdas de 1 a i

maneras(i,j) = maneras(i-1,j-l_i) + maneras(i-1,j) si  l_i <= j
				 maneras(i-1,j)                    si l_i > j
para 1 <= i <= N, 1 <= j <= L

CASOS BASE: maneras(i,0) = 1  si 0 <= i <= N
			maneras(0,j) = 0  si 1 <= j <= L
*/

long long int manerasPD(std::vector<int> const& l, int L) {
	//casos base
	std::vector<long long int> maneras(L + 1, 0);
	maneras[0] = 1;

	//llevamos a cabo los casos recursivos sobreescribiendo el vector de derecha a izquierda
	for (int i = l.size() - 1; i >= 0; --i) {
		for (int j = L; j > 0; --j) {
			if (l[i] <= j) maneras[j] = maneras[j] + maneras[j - l[i]];
			//en caso contrario el valor no cambia
		}
	}

return maneras[L];
}

/* Nos piden necesito(N,L) si tenemos la funcion:
necesito(i,j) = numero minimo de cuerdas necesarias de entre las dadas para obtener una de longitud j si solo
				consideramos las cuerdas de 1 a i

necesito(i,j) = min{ necesito(i-1,j-l_i) + 1, necesito(i-1,j)} si  l_i <= j
				necesito(i-1,j)                                si l_i > j
para 1 <= i <= N, 1 <= j <= L

CASOS BASE: necesito(i,0) = 0        si 0 <= i <= N
			necesito(0,j) = +inf     si 1 <= j <= L
*/

int necesitoPD(std::vector<int> const& l, int L) {
	//casos base
	std::vector<int> necesito(L + 1, INF);
	necesito[0] = 0;

	//llevamos a cabo los casos recursivos sobreescribiendo el vector de derecha a izquierda
	for (int i = l.size() - 1; i >= 0; --i) {
		for (int j = L; j > 0; --j) {
			if (l[i] <= j) necesito[j] = std::min(necesito[j], necesito[j - l[i]] + 1);
			//en caso contrario el valor no cambia
		}
	}

return necesito[L];
}

/* Nos piden minCoste(N,L) si tenemos la funcion:
minCoste(i,j) = minimo coste de cuerdas con el que es posible obtener una de longitud j si solo consideramos las de 1 a i

minCoste(i,j) = min{ minCoste(i-1,j-l_i) + c_i, minCoste(i-1,j)} si  l_i <= j
				minCoste(i-1,j)                                  si l_i > j
para 1 <= i <= N, 1 <= j <= L

CASOS BASE: minCoste(i,0) = 0        si 0 <= i <= N
			minCoste(0,j) = +inf     si 1 <= j <= L
*/

int minCostePD(std::vector<int> const& l, std::vector<int> const& c, int L) {
	//casos base
	std::vector<int> minCoste(L + 1, INF);
	minCoste[0] = 0;

	//llevamos a cabo los casos recursivos sobreescribiendo el vector de derecha a izquierda
	for (int i = l.size() - 1; i >= 0; --i) {
		for (int j = L; j > 0; --j) {
			if (l[i] <= j) minCoste[j] = std::min(minCoste[j], minCoste[j - l[i]] + c[i]);
			//en caso contrario el valor no cambia
		}
	}

return minCoste[L];
}

bool resuelveCaso() {
	int N, L;
	std::cin >> N >> L;

	if (!std::cin) return false;

	std::vector<int> l(N), c(N);
	for (int i = 0; i < N; ++i) std::cin >> l[i] >> c[i];

	if (esPosiblePD(l, L)) {
		std::cout << "SI " << manerasPD(l, L) << ' ' << necesitoPD(l, L) << ' ' << minCostePD(l, c, L) << '\n';
	}
	else std::cout << "NO\n";

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}