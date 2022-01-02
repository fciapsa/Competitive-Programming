#include <iostream>
#include <vector>

//suma acumulada de dias con el mes incluido
const std::vector<int> dias_mes = {0,0, 31,59,90,120,151,181,212,243,273,304,334};

bool resuelveCaso() {
	int d1, m1, a1, d2, m2, a2;
	std::cin >> d1 >> m1 >> a1 >> d2 >> m2 >> a2;

	if (a1 == 0) return false;

	if (d1 != d2 || m1 != m2) {
		int sum1 = a1 * 365 + d1 + dias_mes[m1];

		int sum2 = a2 * 365 + d2 + dias_mes[m2];

		int dif = sum2 - sum1;
		dif -= a2 - a1;
		if (a2 > a1 && (m1 > m2 || (m1 == m2 && d1 > d2))) dif += 1;//no ha llegado a cumplir

		std::cout << dif << '\n';
	}
	else std::cout << "0\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}