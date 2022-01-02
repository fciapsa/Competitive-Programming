#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
	int F, C, aux, almendras;
	std::cin >> F >> C;
	while (std::cin) {
		std::vector<std::vector<char>> mat(F, std::vector<char>(C));
		std::vector<std::vector<int>> acumPorFila(F, std::vector<int>(C,0));
		for (int i = 0; i < F; ++i) {
			std::cin >> mat[i][0];
			if (mat[i][0] == '#') acumPorFila[i][0] = 1;
			for (int j = 1; j < C; ++j) {
				std::cin >> mat[i][j];
				if (mat[i][j] == '#') acumPorFila[i][j] = acumPorFila[i][j - 1] + 1;
				else acumPorFila[i][j] = acumPorFila[i][j - 1];
			}
		}

		std::vector<std::vector<std::vector<std::vector<int>>>> dp(F, 
			std::vector<std::vector<std::vector<int>>>(F, std::vector<std::vector<int>>(C, std::vector<int>(C))));

		for (int i1 = F-1; i1 >= 0; --i1) {
			for (int i2 = i1; i2 < F; ++i2) {
				for (int j1 = C-1; j1 >= 0; --j1) {
					for (int j2 = j1; j2 < C; ++j2) {
						if (i1 == i2 && j1 == j2) dp[i1][i1][j1][j1] = 0;
						else {
							almendras = 0;
							for (int x = i1; x <= i2; ++x) {
								if (j1 == 0) almendras += acumPorFila[x][j2];
								else almendras += (acumPorFila[x][j2] - acumPorFila[x][j1 - 1]);
							}
							if (almendras == 0 || almendras == (i2 - i1 + 1) * (j2 - j1 + 1)) dp[i1][i2][j1][j2] = 0;
							else {
								aux = INT_MAX;
								if (i2 - i1 > 0) {
									for (int k = i1 + 1; k <= i2; ++k) {
										aux = std::min(aux, 1 + dp[i1][k - 1][j1][j2] + dp[k][i2][j1][j2]);
									}
								}
								if (j2 - j1 > 0) {
									for (int k = j1 + 1; k <= j2; ++k) {
										aux = std::min(aux, 1 + dp[i1][i2][j1][k - 1] + dp[i1][i2][k][j2]);
									}
								}
								dp[i1][i2][j1][j2] = aux;
							}
						}
					}
				}
			}
		}
		std::cout << dp[0][F - 1][0][C - 1] << '\n';
	std::cin >> F >> C;
	}
return 0;
}