#include <iostream>

int main() {
	long long int r, fr, h, fh, HH, RR, n1, n2, d1, d2;
	std::cin >> r;
	while (std::cin) {
		std::cin >> fr >> h >> fh >> HH >> RR;

		fr = r - fr;//en vez de los que fallo, los que acierto
		n1 = fr * RR * h;
		n2 = fh * HH * r;

		if (n2*10 <= n1 + n2) std::cout << "APRUEBA\n";
		else std::cout << "SUSPENDE\n";

	std::cin >> r;
	}
return 0;
}