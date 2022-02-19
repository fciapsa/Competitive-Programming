#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

int H, W, val;
std::queue<std::pair<int, int>> q, next_q;

void dfs(std::vector<std::string> const& mat, char c, std::vector<std::vector<int>>& times,int x, int y) {
	if(times[x][y] == -1) times[x][y] = val;

	if (x < H - 1 && times[x + 1][y] == -1 && mat[x + 1][y] == c) {
		dfs(mat, c, times, x + 1, y);
	}
	if (y < W - 1 && times[x][y + 1] == -1 && mat[x][y + 1] == c) {
		dfs(mat, c, times, x, y + 1);
	}

	if (x < H - 1 && y < W - 1) {
		if (times[x + 1][y] == -1 || times[x][y + 1] == -1) next_q.push({ x,y });
	}
	else if (x < H - 1) {
		if (times[x + 1][y]) next_q.push({ x,y });
	}
	else if(y < W-1){
		if (times[x][y + 1] == -1) next_q.push({ x,y });
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> H >> W;
	std::cin.ignore();
	std::vector<std::string> mat(H);
	std::vector<std::vector<int>> times(H, std::vector<int>(W, -1));
	for (int i = 0; i < H; ++i) getline(std::cin, mat[i]);

	val = 0;
	if (mat[0][0] == '#') dfs(mat, '#', times, 0, 0);
	else dfs(mat, '.', times,0,0);
	while (times[H - 1][W - 1] == -1) {
		while (!next_q.empty()) {
			q.push(next_q.front());
			next_q.pop();
		}
		++val;
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			if (mat[i][j] == '#') dfs(mat, '.', times, i, j);
			else dfs(mat, '#', times, i, j);
		}
	}
	
	if (mat[0][0] == '.' && mat[H - 1][W - 1] == '.') std::cout << times[H - 1][W - 1] / 2 << '\n';
	else std::cout << times[H - 1][W - 1] / 2 + 1 << '\n';

return 0;
}