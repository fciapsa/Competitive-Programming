#include <iostream>
#include <queue>
#include <functional>

bool resuelveCaso() {
	int medio, N;
	std::cin >> medio >> N;

	if (medio == 0 && N == 0) return false;

	std::priority_queue<int, std::vector<int>, std::less<int>> izquierda;
	std::priority_queue<int, std::vector<int>, std::greater<int>> derecha;

	int a, b, izq, der;
	std::cin >> a >> b;
	
	if (a > medio && b > medio) {
		derecha.push(a);
		derecha.push(b);
		izquierda.push(medio);

		medio = derecha.top();
		derecha.pop();
	}
	else if (a < medio && b < medio) {
		izquierda.push(a);
		izquierda.push(b);
		derecha.push(medio);

		medio = izquierda.top();
		izquierda.pop();
	}
	else {
		izq = std::min(a, b);
		der = std::max(a, b);
		izquierda.push(izq);
		derecha.push(der);
	}
	std::cout << medio;

	for (int i = 1; i < N; ++i) {
		std::cin >> a >> b;

		if (a > medio && b > medio) {
			derecha.push(a);
			derecha.push(b);
			izquierda.push(medio);

			medio = derecha.top();
			derecha.pop();
		}
		else if (a < medio && b < medio) {
			izquierda.push(a);
			izquierda.push(b);
			derecha.push(medio);

			medio = izquierda.top();
			izquierda.pop();
		}
		else {
			izq = std::min(a, b);
			der = std::max(a, b);
			izquierda.push(izq);
			derecha.push(der);
		}
		std::cout << ' ' << medio;
	}
	std::cout << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}