#include <iostream>
#include <vector>

int main() {
	int T, x, regid;
	bool ok;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		ok = true;
		std::vector<std::vector<bool>> fila(9, std::vector<bool>(10, false)), col(9, std::vector<bool>(10, false))
			, reg(9, std::vector<bool>(10, false));

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				std::cin >> x;

				//no rep por fila
				if (fila[i][x]) ok = false;
				else fila[i][x] = true;

				//no rep por columna
				if (col[j][x]) ok = false;
				else col[j][x] = true;

				//no rep por region
				if (i > 5) {
					if (j > 5) regid = 8;
					else if (j > 2) regid = 7;
					else regid = 6;
				}
				else if (i > 2) {
					if (j > 5) regid = 5;
					else if (j > 2) regid = 4;
					else regid = 3;
				}
				else {
					if (j > 5) regid = 2;
					else if (j > 2) regid = 1;
					else regid = 0;
				}

				if (reg[regid][x]) ok = false;
				else reg[regid][x] = true;
			}
		}

		if (ok) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}