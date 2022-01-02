#include <iostream>
#include <vector>
#include <climits>

/*Nos piden esfuerzo(0,N+1) si definimos la funcion:
	esfuerzo(i,j) = minimo esfuerzo necesario si quedan por realizar los cortes de i+1 a j-1(los otros ya se han realizado)
	con i < j

Para 0 <= i < N, i+1 < j <= N+1 los casos recursivos se definen como:
	esfuerzo(i,j) = min{esfuerzo(i,k) + esfuerzo(k,j) + 2*(marcas[j] - marcas[i])} en i+1 <= k <= j-1

CASOS BASE: esfuerzo(i,i+1) = 0 para 0 <= i <= N

COSTE: En O(N^2) tanto en tiempo como en espacio. De la tabla esfuerzo solo se rellena la parte triangular superior.
*/

bool resuelveCaso() {
	int L, N;
	std::cin >> L >> N;

	if (L == 0 && N == 0) return false;

	std::vector<int> marcas(N + 2);
	marcas[0] = 0;
	marcas[N + 1] = L;
	for (int i = 1; i <= N; ++i) {
		std::cin >> marcas[i];
	}

	std::vector<std::vector<int>> esfuerzo(N + 1, std::vector<int>(N + 2, 0));
	//casos base esfuerzo(i,i+1) ya resueltos en la inicializacion
	//rellenamos el resto de la tabla segun la definicion recursiva, de abajo hacia arriba y de derecha a izquierda
	int aux_min, temp, corte;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = i + 2; j <= N + 1; ++j) {
			aux_min = INT_MAX;
			corte = 2 * (marcas[j] - marcas[i]);
			for (int k = i + 1; k <= j - 1; ++k) {
				temp = esfuerzo[i][k] + esfuerzo[k][j] + corte;
				if (temp < aux_min) aux_min = temp;
			}
			esfuerzo[i][j] = aux_min;
		}
	}

	std::cout << esfuerzo[0][N + 1] << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}