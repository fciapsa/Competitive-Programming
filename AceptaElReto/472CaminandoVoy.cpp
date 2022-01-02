#include <iostream>
#include <vector>

bool comprobar(std::vector<long int> const & V, long int D) {
	bool b = true;
	long int primero = V[0];
	long int ultimo = V[0];
	for (int ind = 1; ind < V.size() && b; ++ind) {
		if (V[ind] > V[ind - 1])
			ultimo = V[ind];
		else {
			primero = V[ind];
			ultimo = V[ind];
		}
		b = ultimo - primero <= D;
	}
	return b;
}

bool resuelveCaso() {
	long int D, n;
	std::cin >> D >> n;
		if (!std::cin) // fin de la entrada
			return false;
  
    std::vector<long int> V(n);
		for (int i = 0; i < n; ++i)
			std::cin >> V[i];
		bool b = comprobar(V, D);
		if (b) std::cout << "APTA\n";
		else std::cout << "NO APTA\n";
		return true;

}
int main() {
	while (resuelveCaso());
	return 0;
}