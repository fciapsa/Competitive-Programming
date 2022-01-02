#include <iostream>
#include <string>
#include <vector>

int DFS(std::vector<std::string> const& mat, std::vector<std::vector<bool>>& visited, int i, int j) {
	visited[i][j] = true;
	int cont = 1;
	if (i > 0 && mat[i - 1][j] == '#' && !visited[i - 1][j]) cont += DFS(mat, visited, i - 1, j);
	if (j < visited[0].size() - 1 && mat[i][j + 1] == '#' && !visited[i][j + 1]) cont += DFS(mat, visited, i, j + 1);
	if (i < visited.size() - 1 && mat[i + 1][j] == '#' && !visited[i + 1][j]) cont += DFS(mat, visited, i + 1, j);
	if (j > 0 && mat[i][j - 1] == '#' && !visited[i][j - 1]) cont += DFS(mat, visited, i, j - 1);

return cont;
}

int main() {
	int F, C;
	std::string s;
	std::cin >> F >> C;
	while (std::cin) {
		std::cin.ignore();
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) {
			getline(std::cin, mat[i]);
		}

		int sol = 0, aux;
		std::vector<std::vector<bool>> visited(F, std::vector<bool>(C, false));
		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (mat[i][j] == '#' && !visited[i][j]) {
					aux = DFS(mat, visited, i, j);
					if (aux > sol) sol = aux;
				}
			}
		}
		std::cout << sol << '\n';
	std::cin >> F >> C;
	}
return 0;
}