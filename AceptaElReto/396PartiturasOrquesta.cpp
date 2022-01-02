#include <iostream>
#include <queue>//priority_queue

struct tGrupo {
	int ini, partes, max;
};

bool operator<(tGrupo const& g1, tGrupo const&g2) {
	return g1.max < g2.max;
}

bool resuelveCaso() {
	int p, n;
	std::cin >> p >> n;

	if (!std::cin) return false;

	std::priority_queue<tGrupo> cola;
	int x;
	tGrupo aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		aux = { x,1,x };
		cola.push(aux);
	}

	aux = cola.top();
	for (int i = n; i < p && aux.max > 1; ++i) {
		cola.pop();
		++aux.partes;
		if (aux.ini % aux.partes == 0) aux.max = aux.ini / aux.partes;
		else aux.max = aux.ini / aux.partes+1;

		cola.push(aux);
		aux = cola.top();
	}

	std::cout << aux.max << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}