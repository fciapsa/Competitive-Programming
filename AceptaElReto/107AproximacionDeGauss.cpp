#include <iostream>
#include <vector>
#include <cmath>

const int TAM = 100000;
std::vector<bool> criba(TAM, true);
std::vector<int> PI(TAM);

void initPI() {
	int cont = 0;
	for (int i = 2; i < TAM; ++i) {
		if (criba[i]) {
			++cont;
			for (int j = 2 * i; j < TAM; j += i) {
				criba[j] = false;
			}
		}
		PI[i] = cont;
	}
}

int main() {
	initPI();
	double n, error1, error2;
	int m;
	std::cin >> n >> m;
	while (n != 0) {
		switch (m) {
		case 0: error1 = 1; break;
		case 1: error1 = 0.1; break;
		case 2: error1 = 0.01; break;
		case 3: error1 = 0.001; break;
		case 4: error1 = 0.0001; break;
		case 5: error1 = 0.00001; break;
		}
		error2 = PI[n]/n - 1/log(n);
		error2 = std::abs(error2);

		if (error2 > error1) std::cout << "Mayor\n";
		else if (error2 == error1) std::cout << "Igual\n";
		else std::cout << "Menor\n";

	std::cin >> n >> m;
	}
return 0;
}