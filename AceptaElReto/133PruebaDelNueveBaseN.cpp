#include <iostream>
#include <string>
#include <cctype>

const int A = 55, ZERO = 48;

int main() {
	int t, B, rD, rd, rc, rr;
	std::string D, d, c, r;
	std::cin >> t;
	for (int m = 0; m < t; ++m) {
		std::cin >> B >> D >> d >> c >> r;
		--B;
		rD = 0; rd = 0; rc = 0; rr = 0;

		for (int i = 0; i < D.size(); ++i) {
			if (isalpha(D[i])) rD += int(D[i]) - A;
			else rD += int(D[i]) - ZERO;
			rD %= B;
		}
		for (int i = 0; i < d.size(); ++i) {
			if (isalpha(d[i])) rd += int(d[i]) - A;
			else rd += int(d[i]) - ZERO;
			rd %= B;
		}
		for (int i = 0; i < c.size(); ++i) {
			if (isalpha(c[i])) rc += int(c[i]) - A;
			else rc += int(c[i]) - ZERO;
			rc %= B;
		}
		for (int i = 0; i < r.size(); ++i) {
			if (isalpha(r[i])) rr += int(r[i]) - A;
			else rr += int(r[i]) - ZERO;
			rr %= B;
		}

		if ((rd * rc + rr)%B == rD) std::cout << "POSIBLEMENTE CORRECTO\n";
		else std::cout << "INCORRECTO\n";
	}
return 0;
}