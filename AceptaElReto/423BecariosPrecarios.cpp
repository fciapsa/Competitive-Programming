#include <iostream>

void leerArbol(int &precarios, int nivel, int nivelPrecario) {
	int hijos;
	std::cin >> hijos;

	if (hijos == 0 && nivel >= nivelPrecario) ++precarios;
	else if (hijos != 0) {
		for (int i = 0; i < hijos; ++i) {
			leerArbol(precarios, nivel + 1, nivelPrecario);
		}
	}
}

bool resuelveCaso() {
	int nivelPrecario;
	std::cin >> nivelPrecario;//numero de jefes a tener como minimo
	++nivelPrecario;//para que coincida con el nivel en el arbol

	if (!std::cin) return false;

	int precarios = 0;
	leerArbol(precarios, 1, nivelPrecario);

	std::cout << precarios << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}