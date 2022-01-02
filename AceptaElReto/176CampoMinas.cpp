#include <iostream>
#include <string>

int main() {
	int N, M;
	std::cin >> M >> N;

	while (N > 0 && M > 0) {
		int sol = 0;
		std::string f1 = "", f2 = "", f3 = "";

		if (N < 3 || M < 3) {
			for (int i = 0; i < N; ++i) {
				std::cin >> f1;
			}
			std::cout << "0\n";
		}
		else {
			//Primera fila a tratar
			std::cin >> f1 >> f2 >> f3;
			for (int i = 1; i < M-1; ++i) {
				if (f2[i] == '-') {
					int cont = 0;
					if (f1[i] == '*') ++cont;
					if (f1[i + 1] == '*') ++cont;
					if (f2[i + 1] == '*') ++cont;
					if (f3[i + 1] == '*') ++cont;
					if (f3[i] == '*') ++cont;
					if (f3[i - 1] == '*') ++cont;
					if (f2[i - 1] == '*') ++cont;
					if (f1[i - 1] == '*') ++cont;

					if (cont >= 6) ++sol;
				}
			}

			//Las demas
			int k = 3;
			while (k < N) {
				f1 = f2;
				f2 = f3;
				std::cin >> f3;

				for (int i = 1; i < M-1; ++i) {
					if (f2[i] == '-') {
						int cont = 0;
						if (f1[i] == '*') ++cont;
						if (f1[i + 1] == '*') ++cont;
						if (f2[i + 1] == '*') ++cont;
						if (f3[i + 1] == '*') ++cont;
						if (f3[i] == '*') ++cont;
						if (f3[i - 1] == '*') ++cont;
						if (f2[i - 1] == '*') ++cont;
						if (f1[i - 1] == '*') ++cont;

						if (cont >= 6) ++sol;
					}
				}
			++k;
			}
		std::cout << sol << '\n';
		}
	std::cin >> M >> N;
	}
return 0;
}