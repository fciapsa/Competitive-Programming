#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct coord {
	int x, y;
};

int main() {
	coord act;
	int n;
	std::cin >> n;
	while (n != 0) {
		std::cin.ignore();
		std::vector<std::string> data(n);
		for (int i = 0; i < n; ++i) getline(std::cin, data[i]);

		std::vector<std::vector<int>> ways(n, std::vector<int>(n));
		ways[n - 1][0] = 1;
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(n,false));
		visited[n - 1][0] = true;
		std::queue<coord> q;
		q.push({ n - 1,0 });
		while (!q.empty()) {
			act = q.front();
			q.pop();

			if (act.x > 0 && data[act.x-1][act.y] == '.' && !visited[act.x-1][act.y]) {
				visited[act.x - 1][act.y] = true;
				if (act.y > 0) ways[act.x - 1][act.y] += ways[act.x - 1][act.y - 1];
				ways[act.x - 1][act.y] += ways[act.x][act.y];
				q.push({ act.x - 1,act.y });
			}
			if (act.y < n - 1 && data[act.x][act.y + 1] == '.' && !visited[act.x][act.y + 1]) {
				visited[act.x][act.y + 1] = true;
				ways[act.x][act.y + 1] += ways[act.x][act.y];
				if (act.x < n-1) ways[act.x][act.y + 1] += ways[act.x + 1][act.y+1];
				q.push({ act.x,act.y + 1 });
			}
		}
		std::cout << ways[0][n - 1] << '\n';
	std::cin >> n;
	}
return 0;
}