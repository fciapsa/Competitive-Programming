#include <iostream>

const int TAM = 10000;

int main() {
	int N, cant, sol;
	std::cin >> N;
	while (N--) {
		std::cin >> cant;
		sol = TAM;
		if (cant % 2 == 0) {
			cant /= 2;
			sol /= 2;
			if (cant % 2 == 0) {
				cant /= 2;
				sol /= 2;
				if (cant % 2 == 0) {
					cant /= 2;
					sol /= 2;
					if (cant % 2 == 0) {
						cant /= 2;
						sol /= 2;
					}
				}
			}
		}
		if (cant % 5 == 0) {
			cant /= 5;
			sol /= 5;
			if (cant % 5 == 0) {
				cant /= 5;
				sol /= 5;
				if (cant % 5 == 0) {
					cant /= 5;
					sol /= 5;
					if (cant % 5 == 0) {
						cant /= 5;
						sol /= 5;
					}
				}
			}
		}
		std::cout << sol << '\n';
	}
return 0;
}