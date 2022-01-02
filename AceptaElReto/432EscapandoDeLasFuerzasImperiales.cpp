#include <iostream>
#include <string>
#include <vector>

int F, C;
bool ok;

void dfs(std::vector<std::string> const& mat, std::vector<std::vector<bool>>& marked,int x,int y) {
	marked[x][y] = true;
	if (mat[x][y] == 'F') ok = true;

	if (x > 0 && mat[x - 1][y] != '*' && !marked[x - 1][y]) dfs(mat, marked, x - 1, y);
	if (x < F - 1 && mat[x + 1][y] != '*' && !marked[x + 1][y]) dfs(mat, marked, x + 1, y);
	if (y > 0 && mat[x][y - 1] != '*' && !marked[x][y - 1]) dfs(mat, marked, x, y - 1);
	if (y < C - 1 && mat[x][y + 1] != '*' && !marked[x][y + 1]) dfs(mat, marked, x, y + 1);
}

int main() {
	int x, y;
	bool start;
	std::cin >> F >> C;
	while (std::cin) {
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) std::cin >> mat[i];

		start = false;
		for (int i = 0; i < F && !start; ++i) {
			for (int j = 0; j < C && !start; ++j) {
				if (mat[i][j] == 'S') {
					start = true;
					x = i;
					y = j;
				}
			}
		}

		ok = false;
		std::vector<std::vector<bool>> marked(F, std::vector<bool>(C, false));
		dfs(mat, marked,x,y);
		if (ok) std::cout << "SI\n";
		else std::cout << "NO\n";

	std::cin >> F >> C;
	}
return 0;
}