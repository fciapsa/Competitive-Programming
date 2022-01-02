#include <iostream>

int main() {
	int n, cont, x, hh, mm, ss;
	std::cin >> n;
	while (n != 0) {
		cont = 0;
		std::cin >> x;
		while (x != 0) {
			cont += x * n;
			std::cin >> x;
		}

		hh = cont / 3600;
		cont %= 3600;
		mm = cont / 60;
		cont %= 60;
		ss = cont;

		if (hh < 10) std::cout << '0' << hh << ':';
		else std::cout << hh << ':';
		if (mm < 10) std::cout << '0' << mm << ':';
		else std::cout << mm << ':';
		if (ss < 10) std::cout << '0' << ss << '\n';
		else std::cout <<  ss << '\n';

	std::cin >> n;
	}
	return 0;
}