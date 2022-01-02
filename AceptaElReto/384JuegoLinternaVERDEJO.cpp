#include <iostream>
#include <vector>
#include <stack>

bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) std::cin >> v[i];

	bool ok = true;//evalua a false si pierde
	std::stack<int> pila;//guarda los valores que podrian convertirse en medianos
	int mm = -1;//mejor mediano
	pila.push(v[n - 1]);

	for (int i = n - 2; i >= 0 && ok; --i) {
		while (!pila.empty() && v[i] > pila.top()) {
			mm = pila.top();
			pila.pop();
		}

		if (v[i] > mm) pila.push(v[i]);
		else if (v[i] < mm) ok = false;

	}

	if(ok) std::cout << "SIEMPRE PREMIO\n";
	else std::cout << "ELEGIR OTRA\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}