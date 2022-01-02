#include <iostream>

int main() {
	int N;
	long long int pos1, pos2, neg1, neg2, aux, sol1, sol2, sol3;
	std::cin >> N;
	while (N != 0) {
		if (N == 2) {
			std::cin >> pos1 >> pos2;
			std::cout << pos1 * pos2 << '\n';
		}
		else {
			pos1 = 0; pos2 = 0;
			neg1 = 0;  neg2 = 0;
			for (int i = 0; i < N; ++i) {
				std::cin >> aux;
				if (aux > 0) {
					if (aux > pos1) {
						pos2 = pos1;
						pos1 = aux;
					}
					else if (aux > pos2) pos2 = aux;
				}
				else {
					if (aux < neg1) {
						neg2 = neg1;
						neg1 = aux;
					}
					else if (aux < neg2) neg2 = aux;
				}
			}
			pos1 *= pos2;
			neg1 *= neg2;
			if (pos1 > neg1) std::cout << pos1 << '\n';
			else std::cout << neg1 << '\n';
		}

	std::cin >> N;
	}
return 0;
}