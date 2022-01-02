#include <iostream>
#include <string>
#include <set>

int main() {
	int n, x, aux;
	std::string tunel;
	getline(std::cin, tunel);
	while (std::cin) {
		std::set<int> puntos;
		puntos.insert(0);//salida Peninsula
		puntos.insert(tunel.size() + 1);//salida Islas
		for (int i = 0; i < tunel.size(); ++i) if (tunel[i] == 'T') puntos.insert(i + 1);

		std::cin >> n;
		for(int i = 0; i < n; ++i){
			std::cin >> x;
			auto it = puntos.lower_bound(x);
			if (*it == x) std::cout << "AQUI\n";
			else {
				aux = *it;
				--it;
				if (x - *it < aux - x) std::cout << "PENINSULA\n";
				else if (aux - x < x - *it) std::cout << "ISLAS\n";
				else {
					if (x > tunel.size() + 1 - x) std::cout << "ISLAS\n";
					else std::cout << "PENINSULA\n";
					
				}
			}
		}

	std::cin.ignore();
	getline(std::cin, tunel);
	}
return 0;
}