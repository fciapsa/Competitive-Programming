#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> c(N);
		for (int i = 0; i < N; ++i) std::cin >> c[i];

		std::vector<std::vector<int>> maxComida(N, std::vector<int>(N));
        //casos base
		for (int i = 0; i < N; ++i) maxComida[i][i] = c[i];
		for (int i = 0, j = 1; j < N; ++i, ++j) maxComida[i][j] = std::max(c[i], c[j]);
		//rellenamos el resto de la tabla segun los casos recursivos
		int aux1, aux2;
		for (int d = 2; d < N; ++d) {
			for (int i = 0, j = d; j < N; ++i, ++j) {
				if (c[i + 1] > c[j]) aux1 = c[i] + maxComida[i + 2][j];
				else aux1 = c[i] + maxComida[i + 1][j - 1];

				if (c[i] > c[j - 1]) aux2 = c[j] + maxComida[i + 1][j - 1];
				else aux2 = c[j] + maxComida[i][j - 2];

				maxComida[i][j] = std::max(aux1, aux2);
			}
		}
		std::cout << maxComida[0][N - 1] << '\n';

	std::cin >> N;
	}
return 0;
}