#include <iostream>
#include <vector>
#include <string>

const int TAM = 8;

int main() {
	int C, F, mC, mF, aux;
	std::cin >> C >> F >> mC >> mF;
	while (mC != 0) {
		std::cin.ignore();
		std::vector<std::string> mesa(F);
		for (int i = 0; i < F; ++i) {
			getline(std::cin, mesa[i]);
		}
		std::vector<std::vector<int>> inRanges(C, std::vector<int>(F - mF + 1));
		for (int j = 0; j < C; ++j) {
			aux = 0;
			for (int i = 0; i < mF; ++i) {
				if (mesa[i][j] != '.') ++aux;
			}
			inRanges[j][0] = aux;
			for (int i = mF; i < F; ++i) {
				if (mesa[i - mF][j] != '.') --aux;
				if (mesa[i][j] != '.') ++aux;
				inRanges[j][i - mF + 1] = aux;
			}
		}

		std::vector<int> sol(TAM);
		for (int i = 0; i+ mF <= F; ++i) {
			aux = 0;
			for (int j = 0; j < mC; ++j) aux += inRanges[j][i];
			if (aux < TAM) ++sol[aux];

			for (int j = mC; j < C; ++j) {
				aux -= inRanges[j - mC][i];
				aux += inRanges[j][i];
				if (aux < TAM) ++sol[aux];
			}
		}

		std::cout << sol[0];
		for (int i = 1; i < TAM; ++i) std::cout << ' ' << sol[i];
		std::cout << '\n';

	std::cin >> C >> F >> mC >> mF;
	}
return 0;
}