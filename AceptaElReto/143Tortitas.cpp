#include <iostream>
#include <stack>
#include <deque>

bool resuelveCaso() {
	std::stack<int> pila; std::deque<int> aux;
	int x;
	
	std::cin >> x;

	if (x == -1) return false;

	while (x != -1) {
		pila.push(x);
		std::cin >> x;
	}

	int vueltas;
	std::cin >> vueltas;

	for (int i = 0; i < vueltas; ++i) {
		std::cin >> x;

		//coger
		for (int j = 0; j < x; ++j) {
			aux.push_back(pila.top());
			pila.pop();
		}

		//meter dadas la vuelta
		while (!aux.empty()) {
			pila.push(aux.front());
			aux.pop_front();
		}
	}

	std::cout << pila.top() << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}