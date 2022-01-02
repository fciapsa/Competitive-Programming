#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


void modificar(std::string &cadena) {
	int i = 0;
	while (i < cadena.size()) {
		if (isalpha(cadena[i]) && isupper(cadena[i])) cadena[i] = tolower(cadena[i]);
		else if (!isalpha(cadena[i])) {
			cadena.erase(cadena.begin() + i);
			--i;
		}
		++i;
	}
}

bool resolver(std::string &cad1, std::string &cad2) {
	bool seguir = true;
	modificar(cad1);
	modificar(cad2);
	sort(cad1.begin(), cad1.end());
	sort(cad2.begin(), cad2.end());
	for (int i = cad1.size(); i >= 0 && seguir; --i) {
		if (cad1[i] != cad2[i] && cad1[i] != ' ') seguir = false;
	}
	return seguir;
}

void resuelveCaso() {
	std::string cad1 = "", cad2 = ""; char c = '\n';
	//Leer los datos de entrada
	getline(std::cin, cad1);
	getline(std::cin, cad2);
	//Resolver el caso
	if (resolver(cad1, cad2)) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int numCasos = 0; char c = '\n';
	std::cin >> numCasos;
	std::cin.get(c);
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}
