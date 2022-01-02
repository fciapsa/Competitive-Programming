#include <iostream>
#include <vector>
#include <climits>

/*Nos piden minMonedas[0][precio] si definimos la funcion:
	minMonedas(i,j) = minima cantidad de monedas que necesitamos emplear para pagar exactamente el valor j si consideramos
					  solo las monedas de la i a la N-1

Para 0 <= i < N, 1 <= j <= precio los casos recursivos se definen como:
	minMonedas(i,j) = minMonedas(i+1,j)                                                             si val[i] > j
					  min{minMonedas(i+1,j), min_{k : k*val[i] <= j}{monedas(i+1,j-k*val[i]) + k} } si val[i] <= j

CASOS BASE: minMonedas(i,0) = 0    para 0 <= i <= N
			minMonedas(N,j) = +inf para 1 <= j <= precio
*/

//NOTA IMPORTANTE: Para reconstruir la solucion correcta cuando hay varias, me fue NECESARIO hacer la recursion top-down

void minMonedasPD(std::vector<int> const& val, std::vector<int> const& cant, int const& precio) {
	const int N = val.size();
	std::vector<std::vector<int>> minMonedas(N + 1, std::vector<int>(precio + 1, INT_MAX));
	//casos base
	//for (int j = 1; j <= precio; ++j) minMonedas[0][j] = INT_MAX;
	for (int i = 0; i <= N; ++i) minMonedas[i][0] = 0;

	//rellenamos el resto de la tabla segun la definicion de los casos recursivos
	int aux_min;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = precio; j > 0; --j) {
			aux_min = minMonedas[i + 1][j];
			for (int k = 1; k <= cant[i] && k * val[i] <= j; ++k) {
				if (minMonedas[i + 1][j - k * val[i]] != INT_MAX) {
					if (minMonedas[i + 1][j - k * val[i]] + k < aux_min) {
						aux_min = minMonedas[i + 1][j - k * val[i]] + k;
					}
				}
			}
			minMonedas[i][j] = aux_min;
		}
	}


	if (minMonedas[0][precio] != INT_MAX) {
		std::cout << "SI";
		std::vector<int> need(N);
		int i = 0, j = precio;
		bool para;
		while (j > 0) {
			para = false;
			for (int k = cant[i]; k >= 0 && !para; --k) {
				if (k * val[i] <= j) {
					if (minMonedas[i][j] == minMonedas[i + 1][j - k * val[i]] + k) {
						need[i] = k;
						j -= (k * val[i]);
						++i;
						para = true;
					}
				}
			}
		}
		for (int k = 0; k < N; ++k) {
			std::cout << ' ' << need[k];
		}
		std::cout << '\n';
	}
	else std::cout << "NO\n";
}

int main() {
	int N;
	std::cin >> N;
	while (std::cin) {
		std::vector<int> val(N);
		for (int i = 0; i < N; ++i) std::cin >> val[i];
		std::vector<int> cant(N);
		for (int i = 0; i < N; ++i) std::cin >> cant[i];
		int precio;
		std::cin >> precio;

		minMonedasPD(val, cant, precio);
		std::cin >> N;
	}
return 0;
}
