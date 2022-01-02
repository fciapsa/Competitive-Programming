#include <iostream>
#include <vector>
#include <string>

struct resultados {
	bool a = false, b = false, c = false;
};

int main() {
	std::string s;
	std::cin >> s;
	while (std::cin) {
		if (s.size() > 1) {
			std::vector<std::vector<resultados>> tabla(s.size(), std::vector<resultados>(s.size()));
			//casos base
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == 'a') tabla[0][j].a = true;
				else if (s[j] == 'b') tabla[0][j].b = true;
				else tabla[0][j].c = true;
			}

			for (int i = 1, hasta = s.size()-1; i < s.size(); ++i, --hasta) {
				for (int j = 0; j < hasta; ++j) {

					for (int k = 0; k < i; ++k) {
						//se puede obtener una a (ac | bc | ca)
						if ((tabla[k][j].a && tabla[i-k-1][j + k + 1].c) || (tabla[k][j].b && tabla[i-k-1][j + k + 1].c) ||
							(tabla[k][j].c && tabla[i-k-1][j + k + 1].a)) tabla[i][j].a = true;
						//se puede obtener una b (aa | ab | bb)
						if ((tabla[k][j].a && tabla[i - k - 1][j + k + 1].a) || (tabla[k][j].a && tabla[i - k - 1][j + k + 1].b) ||
							(tabla[k][j].b && tabla[i - k - 1][j + k + 1].b)) tabla[i][j].b = true;
						//se puede obtener una c (ba | cb | cc)
						if ((tabla[k][j].b && tabla[i - k - 1][j + k + 1].a) || (tabla[k][j].c && tabla[i - k - 1][j + k + 1].b) ||
							(tabla[k][j].c && tabla[i - k - 1][j + k + 1].c)) tabla[i][j].c = true;
					}
				}

			}

			if (tabla[s.size() - 1][0].a) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
		else {
			if (s == "a") std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> s;
	}
return 0;
}