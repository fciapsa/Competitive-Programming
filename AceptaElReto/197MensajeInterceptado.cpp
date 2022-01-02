#include <iostream>
#include <string>

bool esVocal(char const& c) {
	return(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

int main() {
	std::string msg, aux1, aux2, aux3;
	int ini, fin;

	while (getline(std::cin, msg)) {
		aux1 = "";
		aux2 = "";
		for (int i = 0; i < msg.size(); ++i) {
			if (i % 2 == 0) aux1 += msg[i];
			else aux2 = msg[i] + aux2;
		}

		aux1 += aux2;//mensaje con el paso 2 deshecho
		ini = 0; fin = 0;
		aux3 = "";
		for (int i = 0; i < aux1.size(); ++i) {
			if (esVocal(aux1[i])) {
				while (fin >= ini) {
					aux3 += aux1[fin];
					--fin;
				}
				if (i != ini) aux3 += aux1[i];
				ini = i + 1;
				fin = i + 1;
			}
			else if (i != ini) ++fin;
		}
		if (fin < aux1.size()) {
			while (fin >= ini) {
				aux3 += aux1[fin];
				--fin;
			}
		}

		std::cout << msg << " => " << aux3 << '\n';
	}
return 0;
}