#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

int main() {
	int aux;
	std::cin >> aux;
	while (aux != 0) {
		std::vector<int> v;
		v.push_back(aux);

		std::cin >> aux;
		while (aux != 0) {
			v.push_back(aux);
			std::cin >> aux;
		}

		if (v.size() == 1) std::cout << v[0] << '\n';
		else {
			sort(v.begin(), v.end(), std::greater<int>());
			if (v[0] == v[1]) std::cout << "NO\n";
			else {
				std::stack<int> pila;
				pila.push(v[0]);

				int i = 1, tam = v.size(), tamMenos = tam - 1;
				bool ok = true;
				while (i < tam && ok) {
					if (i < tamMenos) {
						if (v[i] == v[i + 1]) pila.push(v[i]);
						else ok = false;
					}
					else if (i == tamMenos) ok = false;
					i += 2;
				}
				if (!ok) std::cout << "NO\n";
				else {
					std::stack<int> pila_aux;

					std::cout << pila.top();
					if (pila.top() != v[0]) pila_aux.push(pila.top());
					pila.pop();
					while (!pila.empty()) {
						std::cout << ' ' << pila.top();
						if (pila.top() != v[0]) pila_aux.push(pila.top());
						pila.pop();
					}
					while (!pila_aux.empty()) {
						std::cout << ' ' << pila_aux.top();
						pila_aux.pop();
					}
					std::cout << '\n';
				}
			}
		}

		std::cin >> aux;
	}
return 0;
}