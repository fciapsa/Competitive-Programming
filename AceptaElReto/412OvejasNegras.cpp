#include <iostream>
#include <vector>
#include <string>

void dfs(std::vector<std::string> &mat, std::vector<std::vector<bool>> &marked, int x, int y) {
	marked[x][y] = true;
	mat[x][y] = 'X';

	int i = x - 1, j = y;
	if (i >= 0 && mat[i][j] == '.') dfs(mat, marked, i, j);
	i = x;
	j = y - 1;
	if (j >= 0 && mat[i][j] == '.') dfs(mat, marked, i, j);
	j = y + 1;
	if (j < mat[0].size() && mat[i][j] == '.') dfs(mat, marked, i, j);
	i = x + 1;
	j = y;
	if (i < mat.size() && mat[i][j] == '.') dfs(mat, marked, i, j);
}

int main() {
	int c, f;
	bool b;
	std::cin >> c >> f;
	while (std::cin) {
		std::vector<std::string> mat(f);
		for (int i = 0; i < f; ++i) std::cin >> mat[i];

		std::vector<std::vector<bool>> marked(f, std::vector<bool>(c, false));
		dfs(mat, marked, 0, 0);

		b = false;
		for (int i = 0; i < f && !b; ++i) {
			for (int j = 0; j < c && !b; ++j) {
				if (mat[i][j] == '.') b = true;
			}
		}

		if (b) std::cout << "SI\n";
		else std::cout << "NO\n";

	std::cin >> c >> f;
	}
return 0;
}