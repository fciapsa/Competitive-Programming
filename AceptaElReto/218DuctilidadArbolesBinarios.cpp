#include <iostream>
#include <vector>

void reconstruir(std::vector<int> const& postord, std::vector<int> const& inord, std::vector<int>& sol, int k, int ini, int fin) {
	int raiz = postord[k];

	int i = ini;
	while (inord[i] != raiz) ++i;

	if (i == ini) {
		if (i == fin) sol.push_back(raiz);
		else {
			sol.push_back(raiz);
			reconstruir(postord, inord, sol, k - 1, i + 1, fin);
		}
	}
	else {
		if (i == fin) {
			sol.push_back(raiz);
			reconstruir(postord, inord, sol, k - 1, ini, i - 1);
		}
		else {
			sol.push_back(raiz);
			reconstruir(postord, inord, sol, k - (fin-i)-1, ini, i - 1);
			reconstruir(postord, inord, sol, k - 1, i + 1, fin);
		}
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> inord(N), postord(N);
	for (int i = 0; i < N; ++i) std::cin >> inord[i];
	for (int i = 0; i < N; ++i) std::cin >> postord[i];

	std::vector<int> sol;
	reconstruir(postord, inord,sol, N - 1, 0, N - 1);

	std::cout << sol[0];
	for (int i = 1; i < N; ++i) std::cout << ' ' << sol[i];
	std::cout << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}