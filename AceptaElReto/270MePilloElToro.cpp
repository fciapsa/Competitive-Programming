#include <iostream>
#include <string>
#include <map>

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::map<std::string, int> notas;
	std::string nomb, calific;
	for (int i = 0; i < N; ++i) {
		std::cin.ignore();
		getline(std::cin, nomb);
		std::cin >> calific;
		if (calific == "CORRECTO") ++notas[nomb];
		else --notas[nomb];
	}

	for (auto it = notas.begin(); it != notas.end(); ++it) {
		if (it->second != 0) std::cout << it->first << ", " << it->second << '\n';
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}