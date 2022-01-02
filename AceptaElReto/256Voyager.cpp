#include <iostream>
#include <string>
#include <algorithm>

bool resuelve() {
	std::string a, b, c;
	std::cin >> a;

	if (!std::cin) return false;

	std::cin >> b >> c;
	//completo para tener el mismo numero de digitos en todos los numeros
	int tam = std::max(std::max(a.size(), b.size()), c.size());
	while (a.size() < tam) a = '0' + a;
	while (b.size() < tam) b = '0' + b;
	while (c.size() < tam) c = '0' + c;

	std::string sol = "";
	bool ok = true;
	for (int i = 0; i < tam && ok; ++i) {
		if (a[i] == b[i]) sol += a[i];
		else if (a[i] == c[i]) sol += a[i];
		else if (b[i] == c[i]) sol += b[i];
		else ok = false;
	}

	if (ok) {
		int i = 0;
		while (i < tam && sol[i] == '0') ++i;
		if (i == tam) std::cout << "0\n";
		else {
			while (i < tam) {
				std::cout << sol[i];
				++i;
			}
			std::cout << '\n';
		}
	}
	else std::cout << "RUIDO COSMICO\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}
