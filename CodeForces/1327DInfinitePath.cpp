#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int explore(std::vector<int> const& cycle, std::vector<int> const& colores) {
	for (int i = 1; i <= cycle.size(); ++i) {//salto, se genera un ciclo con ese salto al elevar el actual a i
		if (cycle.size() % i != 0) continue;//si no es divisor no da lugar a un ciclo de tamano menor???
		for (int j = 0; j < i; j++) {//inicio del ciclo resultante de elevar el actual a i que voy a explorar
			int cl = colores[cycle[j]];
			bool flag = true;
			for (int t = j; t < cycle.size() && flag; t += i) {
				flag = colores[cycle[t]] == cl;
			}
			if (flag) return i;//para i == cycle.size() siempre ocurre
		}
	}
}

int main() {
	int t, n;
	std::cin >> t;
	for (int m = 0; m < t; ++m) {
		std::cin >> n;
		std::vector<int> act(n);
		for (int i = 0; i < n; ++i) act[i] = i;
		std::vector<int> perm(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> perm[i]; 
			--perm[i];
		}
		std::vector<int> colores(n);
		for (int i = 0; i < n; ++i) std::cin >> colores[i];

		std::vector<bool> visited(n, false);
		int min = n;
		for (int i = 0; i < n && min > 1; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				std::vector<int> cycle;
				cycle.push_back(i);
				int next = perm[i];
				while (next != i) {
					visited[next] = true;
					cycle.push_back(next);
					next = perm[next];
				}
				if (cycle.size() == 1) min = 1;
				else min = std::min(min, explore(cycle, colores));
			}
		}
		std::cout << min << '\n';

	}
return 0;
}