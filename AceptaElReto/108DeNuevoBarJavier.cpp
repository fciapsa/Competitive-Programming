#include <iostream>
#include <vector>

int main() {
	char c;
	double d, min, max, sum;
	double nComidas, nVentas;
	std::string tMin, tMax;
	bool rep1, rep2;
	std::cin >> c >> d;
	while (std::cin) {
		std::vector<double> v(5);//D A M I C
		nComidas = 0;
		nVentas = 0;
		while (c != 'N') {
			++nVentas;
			if (c == 'A') ++nComidas;
			switch (c) {
			case 'D': v[0] += d; break;
			case 'A': v[1] += d; break;
			case 'M': v[2] += d; break;
			case 'I': v[3] += d; break;
			case 'C': v[4] += d; break;
			}
			std::cin >> c >> d;
		}

		min = v[0];
		tMin = "DESAYUNOS";
		max = v[0];
		tMax = "DESAYUNOS";
		sum = v[0];
		rep1 = false;
		rep2 = false;
		for (int i = 1; i < 5; ++i) {
			sum += v[i];
			if (v[i] < min) {
				min = v[i];
				rep1 = false;
				switch (i) {
				case 1: tMin = "COMIDAS"; break;
				case 2: tMin = "MERIENDAS"; break;
				case 3: tMin = "CENAS"; break;
				case 4: tMin = "COPAS"; break;
				}
			}
			else if (v[i] == min) rep1 = true;
			if (v[i] > max) {
				max = v[i];
				rep2 = false;
				switch (i) {
				case 1: tMax = "COMIDAS"; break;
				case 2: tMax = "MERIENDAS"; break;
				case 3: tMax = "CENAS"; break;
				case 4: tMax = "COPAS"; break;
				}
			}
			else if (v[i] == max) rep2 = true;
		}

		if (rep2)std::cout << "EMPATE#";
		else std::cout << tMax << '#';
		if (rep1) std::cout << "EMPATE#";
		else std::cout << tMin << '#';
		if (nComidas > 0 && v[1] / nComidas > sum / nVentas) std::cout << "SI\n";
		else std::cout << "NO\n";

	std::cin >> c >> d;
	}
return 0;
}