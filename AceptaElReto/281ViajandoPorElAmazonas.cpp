#include <iostream>
#include <vector>

int main() {
	int N, min, aux;
	std::cin >> N;
	while (std::cin) {
		std::vector<std::vector<int>> c(N, std::vector<int>(N));
		for (int i = 0; i < N-1; ++i) {
			for (int j = i + 1; j < N; ++j) {
				std::cin >> c[i][j];
			}
		}

		std::vector<std::vector<int>> floyd(N, std::vector<int>(N));
		//casos base(de i a i coste cero, ya inicializado)
		for (int i = 0; i < N - 1; ++i) {
			floyd[i][i + 1] = c[i][i + 1];
		}
		for (int i = N-3; i >= 0; --i) {
			for (int j = i + 2; j < N; ++j) {
				min = c[i][j];
				for (int k = i+1; k < j; ++k) {
					aux = floyd[i][k] + floyd[k][j];
					if (aux < min) min = aux;
				}
				floyd[i][j] = min;
			}
		}

		for (int i = 0; i < N-1; ++i) {
			std::cout << floyd[i][i + 1];
			for (int j = i + 2; j < N; ++j) {
				std::cout << ' ' << floyd[i][j];
			}
			std::cout << '\n';
		}

	std::cin >> N;
	}
return 0;
}