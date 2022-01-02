#include <iostream>
#include <string>

int main() {
	int nc;
	std::cin >> nc;
	std::string nomb, aux;
	int cant; bool ult;
	for (int i = 0; i < nc; ++i) {
		std::cin >> nomb >> cant;
		--cant;
		ult = cant > 0;

		for (int j = 0; j < cant; ++j) {
			std::cin >> aux;
			if (aux == nomb) ult = false;
		}

		std::cin >> aux;
		if (ult && aux == nomb) std::cout << "VERDADERA\n";
		else std::cout << "FALSA\n";
	}
return 0;
}