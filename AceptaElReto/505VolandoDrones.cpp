#include <iostream>
#include <algorithm>
#include <queue>

bool resuelveCaso() {
	int N, A, B;
	std::cin >> N >> A >> B;

	if (!std::cin) return false;

	std::priority_queue<int> p9, p1;
	int aux;
	for (int i = 0; i < A; ++i) {
		std::cin >> aux;
		p9.push(aux);
	}
	for (int i = 0; i < B; ++i) {
		std::cin >> aux;
		p1.push(aux);
	}

	long long int cont = 0; bool first = true;
	while (p9.size() > 0 && p1.size() > 0) {
		int tam = std::min(p9.size(), p1.size());
		tam = std::min(N, tam);

		std::vector<int> aux1, aux2;
		for (int i = 0; i < tam; ++i) {

			int d1 = p9.top();
			p9.pop();
			int d2 = p1.top();
			p1.pop();


			int gasta = std::min(d1, d2);
			cont += gasta;
			d1 -= gasta;
			d2 -= gasta;
			if (d1 > 0) aux1.push_back(d1);
			else if (d2 > 0)aux2.push_back(d2);
		}

		for (int i = 0; i < aux1.size(); ++i) p9.push(aux1[i]);
		for (int i = 0; i < aux2.size(); ++i) p1.push(aux2[i]);

		if (first) {
			std::cout << cont;
			first = false;
		}
		else std::cout << ' ' << cont;

		cont = 0;
	}
	std::cout << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}