#include <iostream>
#include <vector>

int main() {
	int hh1, mm1, hh2, mm2, digit, cont;
	char aux;
	std::cin >> hh1 >> aux >> mm1 >> hh2 >> aux >> mm2 >> digit;
	while (hh1 != 24) {
		cont = 0;
		while (hh1 != hh2 || mm1 != mm2) {
			if (hh1 % 10 == digit || hh1 / 10 == digit || mm1 % 10 == digit || mm1 / 10 == digit) ++cont;

			++mm1;
			if (mm1 == 60) {
				mm1 = 0;
				++hh1;
			}
		}
		if (hh1 % 10 == digit || hh1 / 10 == digit || mm1 % 10 == digit || mm1 / 10 == digit) ++cont;
		std::cout << cont << '\n';

	std::cin >> hh1 >> aux >> mm1 >> hh2 >> aux >> mm2 >> digit;
	}
return 0;
}