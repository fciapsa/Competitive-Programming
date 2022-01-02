#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int sol = 0;
	std::vector<float> puntos(7);
    // leer los datos de la entrada
	for (int i = 0; i < puntos.size(); ++i) std::cin >> puntos[i];
    if (! std::cin)
        return false;
    
	sort(puntos.begin(), puntos.end());
	for (int i = 2; i < puntos.size() - 2; ++i) sol += puntos[i]*2;
    // escribir sol
	std::cout << sol << '\n';
    return true;   
}

int main() {
    while (resuelveCaso());
    return 0;
}