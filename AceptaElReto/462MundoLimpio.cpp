#include <iostream>

const int DIA = 86400, HORA = 3600, MIN = 60;

int main() {
	int t, hh, mm, ss, d;
	char c;
	long long int n, sol;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		std::cin >> hh >> c >> mm >> c >> ss;
		sol = n * (hh * HORA + mm * 60 + ss);
		d = sol / DIA;
		sol %= DIA;
		hh = sol / HORA;
		sol %= HORA;
		mm = sol / MIN;
		sol %= MIN;
		ss = sol;
		std::cout << d << ' ';
		if (hh < 10) std::cout << '0';
		std::cout << hh << ':';
		if (mm < 10) std::cout << '0';
		std::cout << mm << ':';
		if (ss < 10) std::cout << '0';
		std::cout << ss << '\n';
	}
return 0;
}