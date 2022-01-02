#include <iostream>
#include <vector>
#include <algorithm>

void resolver(char &dia, int &sol, std::vector<int> dias, std::vector<int> dias2) {
	std::sort(dias.begin(), dias.end());
	sol = dias[0] + 1;
	int j = 0;
	while (dias2[j] != dias[0]) ++j;

			switch (j) {
			case 0: dia = 'L'; break;
			case 1: dia = 'M'; break;
			case 2: dia = 'X'; break;
			case 3: dia = 'J'; break;
			case 4: dia = 'V'; break;
			case 5: dia = 'S'; break;
			case 6: dia = 'D'; break;
			case 7: dia = 'L'; break;
			}
}

void resolverCaso() {
	//Leer los datos
	int weeks = 0, sol = 0;
	char c = ' ', dia = ' ';
	std::vector<int> dias(7, 0);
	std::cin >> weeks;
	for (int j = 0; j < weeks; ++j) {
		std::vector<char> pastillas;
		for (int i = 0; i < 7; ++i) {
			std::cin >> c;
			pastillas.push_back(c);
		}
	for (int x = 0; x < pastillas.size(); ++x) {
		if (pastillas[x] == '*') ++dias[x % 7];
	}
	}
	resolver(dia, sol, dias, dias);
	//Mostrar el resultado
	std::cout << dia << ' ' << sol << '\n';
}

int main() {
	int numCasos = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resolverCaso();
system("PAUSE");
return 0;
}