#include <iostream>
#include <vector>
#include <algorithm>

/*Nos piden oro(N,T) si definimos la funcion:
	oro(i,j) = maxima cantidad de oro que podemos recoger teniendo a nuestra disposicion j segundos de inmersion y
			   considerando solo los cofres de 1 a i

Para 1 <= i <= N, 3 <= j <= T los casos recursivos se definen como:
	oro(i,j) = max{ oro(i-1,j), oro(i-1,j - 3*p_i) + c_i} si 3*p_i <= j
			   oro(i-1,j)                                 si 3*p_i > j

CASOS BASE: oro(0,j) = 0 si 0 <= j <= T
			oro(i,j) = 0 si 0 <= j <= 2, 1 <= i <= N

COSTES: Tanto en tiempo como en espacio en O(N*T)
*/

bool resuelveCaso() {
	int T;
	std::cin >> T;

	if (!std::cin) return false;

	int N;
	std::cin >> N;
	std::vector<int> p(N), c(N);
	for (int i = 0; i < N; ++i)std::cin >> p[i] >> c[i];

	std::vector<std::vector<int>> oro(N + 1, std::vector<int>(T + 1));
	//casos base
	for (int j = 0; j <= T; ++j) oro[0][j] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= 2; ++j) {
			oro[i][j] = 0;
		}
	}
	//rellenamos el resto de la tabla segun los casos recursivos
	int necesito;
	for (int i = 1; i <= N; ++i) {
		necesito = 3 * p[i - 1];
		for (int j = 3; j <= T; ++j) {
			if (j < necesito) oro[i][j] = oro[i - 1][j];
			else oro[i][j] = std::max(oro[i - 1][j], oro[i - 1][j - necesito] + c[i - 1]);
		}
	}

	std::cout << oro[N][T] << '\n';
	//reconstruccion de la solucion
	int cofres = 0;
	std::vector<bool> cuales(N, false);
	int j = T;
	for (int i = N; i > 0; --i) {
		if (oro[i][j] > oro[i - 1][j]) {
			cuales[i - 1] = true;
			++cofres;
			j -= 3 * p[i - 1];
		}
	}
	std::cout << cofres << '\n';
	if (cofres > 0) {
		for (int i = 0; i < N; ++i) {
			if (cuales[i]) std::cout << p[i] << ' ' << c[i] << '\n';
		}
	}

	std::cout << "----\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}