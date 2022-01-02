#include <iostream>
#include <vector>
#include <queue>

int BFS(std::vector<int> const& grafo, int K) {
	int dest = grafo.size() - 1, sol = 10000;
	bool solved = false;

	if (dest == 1) return 0;
	else if (dest <= K + 1) return 1;
	else {
		std::vector<bool> marked(grafo.size(), false);
		std::queue<std::pair<int, int>> cola;
		cola.push({ 1,0 });
		marked[1] = true;
		std::pair<int, int> act;

		int aux;
		while (!cola.empty() && !solved) {
			act = cola.front();
			cola.pop();

			for (int i = 1; i <= K && !solved; ++i) {
				aux = grafo[act.first + i];
				if (!marked[aux]) {
					marked[aux] = true;
					if (aux == dest) {
						solved = true;
						sol = act.second + 1;
					}
					else cola.push({ aux, act.second + 1 });
				}
			}
		}

		return sol;
	}
}

bool resuelve() {
	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) return false;

	//inicialmente ninguna casilla es ni serpiente ni escalera
	std::vector<int> grafo;
	for (int i = 0; i <= N * N; ++i) {
		grafo.push_back(i);
	}
	//actualizo el grafo con las serpientes y las escaleras
	int a, b, tot = S + E;
	for (int i = 0; i < tot; ++i) {
		std::cin >> a >> b;
		grafo[a] = b;
	}

	std::cout << BFS(grafo, K) << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}