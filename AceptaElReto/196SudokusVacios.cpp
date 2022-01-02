#include <iostream>
#include <vector>
#include <string>

int sim(int x) {
	switch (x) {
	case 0: return 8;
	case 1:return 7;
	case 2: return 6;
	case 3: return 5;
	case 4: return 4;
	case 5: return 3;
	case 6: return 2;
	case 7: return 1;
	case 8: return 0;
	}
}

int main() {
	int T, cont;
	bool ok;
	std::cin >> T;
	std::cin.ignore();
	std::vector<std::string> mat(9);
	for (int t = 0; t < T; ++t) {
		getline(std::cin, mat[0]);
		for (int i = 0; i < 9; ++i) getline(std::cin, mat[i]);

		ok = true;
		cont = 0;
		for (int i = 0; i < 9 && ok; ++i) {
			for (int j = 0; j < 9 && ok; ++j) {
				if (mat[i][j] != '-') {
					++cont;
					ok = mat[sim(i)][sim(j)] != '-';
				}
			}
		}

		if (ok && cont <= 32) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
	return 0;
}