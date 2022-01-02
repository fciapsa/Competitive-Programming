#include <iostream>
#include <vector>

bool resuelve() {
	int g;
	std::cin >> g;

	if (g == 20) return false;

	std::vector<int> coef(g + 1);
	for (int i = g; i >= 0; --i) std::cin >> coef[i];
	double n;
	std::cin >> n;

	double pos, value, aux, integral = 0;
	for (int i = 0; i < n; ++i) {
		pos = i / n;
		value = coef[0];
		if (g > 0) value += coef[1] * pos;
		aux = pos;
		for (int i = 2; i < coef.size(); ++i) {
			aux *= pos;
			value += coef[i] * aux;
		}

		if (value > 0) {
			if (value <= 1) integral += value/n;
			else integral += 1/n;
		}
	}

	if (integral >= 0.499 && integral <= 0.501) std::cout << "JUSTO\n";
	else if (integral < 0.499) std::cout << "ABEL\n";
	else std::cout << "CAIN\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}