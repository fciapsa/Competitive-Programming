#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct coord {
	int x, y;
};

int main() {
	int N, S;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> data(N);
		for (int i = 0; i < N; ++i) std::cin >> data[i];

		std::cin >> S;
		std::vector<std::vector<int>> tablero(S, std::vector<int>(S));
		for (int i = 0; i < S; ++i) {
			for (int j = 0; j < S; ++j) {
				std::cin >> tablero[i][j];
			}
		}

		std::stack<coord> dfs;
		int cont;
		bool cornerMove = false;
		coord act;
		std::vector<int> comps;
		std::vector<std::vector<bool>> visited(S, std::vector<bool>(S, false));
		for (int i = 0; i < S && !cornerMove; ++i) {
			for (int j = 0; j < S && !cornerMove; ++j) {
				if (tablero[i][j] && !visited[i][j]) {
					cont = 0;
					dfs.push({ i,j });
					visited[i][j] = true;
					while (!dfs.empty()) {
						act = dfs.top();
						dfs.pop();
						++cont;

						if (act.x - 1 >= 0 && act.y - 1 >= 0 && tablero[act.x - 1][act.y - 1]) cornerMove = true;
						if (act.x - 1 >= 0 && tablero[act.x - 1][act.y] && !visited[act.x - 1][act.y]) {
							dfs.push({ act.x - 1,act.y });
							visited[act.x - 1][act.y] = true;
						}
						if (act.x - 1 >= 0 && act.y + 1 < S && tablero[act.x - 1][act.y + 1]) cornerMove = true;
						if (act.y + 1 < S && tablero[act.x][act.y + 1] && !visited[act.x][act.y + 1]) {
							dfs.push({ act.x,act.y + 1 });
							visited[act.x][act.y + 1] = true;
						}
						if (act.x + 1 < S && act.y + 1 < S && tablero[act.x + 1][act.y + 1]) cornerMove = true;
						if (act.x + 1 < S && tablero[act.x + 1][act.y] && !visited[act.x + 1][act.y]) {
							dfs.push({ act.x + 1,act.y });
							visited[act.x + 1][act.y] = true;
						}
						if (act.x + 1 < S && act.y - 1 >= 0 && tablero[act.x + 1][act.y - 1]) cornerMove = true;
						if (act.y - 1 >= 0 && tablero[act.x][act.y - 1] && !visited[act.x][act.y - 1]) {
							dfs.push({ act.x,act.y - 1 });
							visited[act.x][act.y - 1] = true;
						}
					}
					comps.push_back(cont);
				}
			}
		}

		if (cornerMove || data.size() != comps.size()) std::cout << "NO\n";
		else {
			sort(data.begin(), data.end());
			sort(comps.begin(), comps.end());
			bool ok = true;
			for (int i = 0; i < N && ok; ++i) {
				ok = data[i] == comps[i];
			}

			if (ok) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> N;
	}
return 0;
}