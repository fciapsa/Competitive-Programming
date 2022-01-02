#include <iostream>
#include <vector>

int DFS(std::vector<std::vector<int>> const& adyList, std::vector<bool>& visited, int v) {
	visited[v] = true;
	int res = 1;
	for (int i = 0; i < adyList[v].size(); ++i) {
		if (!visited[adyList[v][i]]) res += DFS(adyList, visited, adyList[v][i]);
	}
return res;
}

int main() {
	int T, N, M, a, b, aux, sol;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> N >> M;
		std::vector<std::vector<int>> adyList(N + 1);
		for (int j = 0; j < M; ++j) {
			std::cin >> a >> b;
			adyList[a].push_back(b);
			adyList[b].push_back(a);
		}

		std::vector<bool> visited(N + 1);
		sol = 0;
		for (int j = 1; j <= N; ++j) {
			if (!visited[j]) aux = DFS(adyList, visited, j);
			if (aux > sol) sol = aux;
		}
	std::cout << sol << '\n';
	}
return 0;
}