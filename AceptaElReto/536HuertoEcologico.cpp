#include <iostream>
#include <string>

int main() {
	std::string nomb, sol;
	int tam,stam, abono, sabono, agua, sagua, dist, sdist, N;
	std::cin >> N;
	while (std::cin) {
		std::cin >> stam >> sabono >> sagua >> sdist;
		std::cin.ignore();
		getline(std::cin, sol);
		
		for (int i = 1; i < N; ++i) {
			std::cin >> tam >> abono >> agua >> dist;
			std::cin.ignore();
			getline(std::cin, nomb);

			if (tam > stam) {
				sol = nomb;
				stam = tam;
				sabono = abono;
				sagua = agua;
				sdist = dist;
			}
			else if (tam == stam) {
				if (agua < sagua) {
					sol = nomb;
					sabono = abono;
					sagua = agua;
					sdist = dist;
				}
				else if (agua == sagua) {
					if (dist < sdist) {
						sol = nomb;
						sabono = abono;
						sdist = dist;
					}
					else if (dist == sdist) {
						if (abono < sabono) {
							sol = nomb;	
							sabono = abono;

						}
					}
				}
			}
		}

		std::cout << sol << '\n';

	std::cin >> N;
	}
return 0;
}