#include <string>
#include <iostream>

// lee un árbol binario ESPEJO
std::string leerArbol(char vacio,std::string const&linea, int &i) {
	if (i < linea.size()) {
		if (linea[i] == vacio) {
			++i;
			return "";
		}
		else {// leer recursivamente los hijos
			char raiz = linea[i];
			++i;
			std::string iz = leerArbol(vacio,linea,i);
			std::string dr = leerArbol(vacio,linea,i);

			return raiz + dr + iz;
		}
	}
}

int main() {
	std::string linea;

	while (getline(std::cin,linea)) {
		int i = 0;
		std::string arb = leerArbol(' ',linea, i);

		for (int i = 0; i < arb.size(); ++i) std::cout << arb[i];
		std::cout << '\n';
	}
return 0;
}