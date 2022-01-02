#include <iostream>
#include <queue>
#include <functional>

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> cola;
	int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		cola.push(aux);
	}

	long long int coste = 0, a, b;
	while (cola.size() > 1) {
		a = cola.top();
		cola.pop();
		b = cola.top();
		cola.pop();

		coste += a + b;
		cola.push(a + b);
	}

	std::cout << coste << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}