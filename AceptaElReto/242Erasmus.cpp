#include <iostream>

int main() {
	long int np;
	std::cin >> np;
	while (np != 0) {
		long int x;
		long long int acum, s = 0;

		std::cin >> acum;
		for (long int i = 1; i < np; ++i) {
			std::cin >> x;
			s += x * acum;
			acum += x;
		}
		std::cout << s << '\n';
	std::cin >> np;
	}
return 0;
}