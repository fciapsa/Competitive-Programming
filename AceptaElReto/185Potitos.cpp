#include <iostream>
#include <string>
#include <set>

int main() {
	int N;
	std::cin >> N;

	std::string aux;
	while (N != 0) {//fin entrada
		std::set<std::string> gusta, no_gusta;

		for (int i = 0; i < N; ++i) {
			std::cin >> aux;

			if (aux == "SI:") {
				std::cin >> aux;
				while (aux != "FIN") {
					gusta.insert(aux);
					std::cin >> aux;
				}
			}
			else {
				std::cin >> aux;
				while (aux != "FIN") {
					no_gusta.insert(aux);
					std::cin >> aux;
				}
			}
		}

		bool primero = true;
		std::set<std::string>::iterator it = no_gusta.begin();
		while (it != no_gusta.end()) {
			if (gusta.find(*it) == gusta.end()) {
				if (primero) {
					std::cout << *it;
					primero = false;
				}
				else std::cout << ' ' << *it;
			}
			++it;
		}

		std::cout << '\n';

		std::cin >> N;
	}
return 0;
}