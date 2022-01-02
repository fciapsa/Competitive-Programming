#include <iostream>
#include <vector>
#include <stack>

int cont;

int main() {
	int V, A, a, b, act;
	std::cin >> V >> A;
	while (std::cin) {
		if (V - 1 != A) {
			for (int i = 0; i < A; ++i) std::cin >> a >> b;
			std::cout << "NO\n";
		}
		else {
			cont = 0;
			std::vector<bool> marked(V, false);
			std::vector<std::vector<int>> adyList(V);
			for (int i = 0; i < A; ++i) {
				std::cin >> a >> b;
				adyList[a].push_back(b);
				adyList[b].push_back(a);
			}

			std::stack<int> pila;
			pila.push(0);
			marked[0] = true;
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();
				++cont;

				for (int x : adyList[act]) {
					if (!marked[x]) {
						marked[x] = true;
						pila.push(x);
					}
				}
			}

			if (cont == V) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> V >> A;
	}
return 0;
}