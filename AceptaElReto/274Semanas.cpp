// Nombre del alumno Flavius
// Usuario del Juez DG05


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int A, int S, int D) {
	int sol = 0;
	if (D != 1) {
		sol = (A - (S - D + 1)) / S;
	}
	else sol = A / S;
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int A = 0; int S = 0; int D = 0;
	std::cin >> A >> S >> D;
	int sol = resolver(A, S, D);
	// escribir sol
	std::cout << sol << '\n';

}

int main() {
	int numCasos = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	system("PAUSE");
	return 0;
}