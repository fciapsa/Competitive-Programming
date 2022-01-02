#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

int main() {
	int w, h, n, act;
	std::cin >> w;
	while (w != 0) {
		std::cin >> h >> n;

		std::vector<int> vx(n);
		std::vector<int> vy(n);
		std::vector<std::vector<int>> adyList(n + 2);//0 borde oeste, n+1 borde este 
		for (int i = 0; i < n; ++i) {
			std::cin >> vx[i] >> vy[i];
			if (vx[i] <= 10) {
				adyList[0].push_back(i + 1);
				adyList[i + 1].push_back(0);
			}
			else if (vx[i] + 10 >= w) {
				adyList[n + 1].push_back(i + 1);
				adyList[i + 1].push_back(n + 1);
			}

			for (int j = i - 1; j >= 0; --j) {
				if (std::sqrt((vx[i] - vx[j]) * (vx[i] - vx[j]) + (vy[i] - vy[j]) * (vy[i] - vy[j])) <= 20.0) {
					adyList[i+1].push_back(j+1);
					adyList[j + 1].push_back(i + 1);
				}
			}
		}

		std::vector<bool> marked(n + 2,false);
		std::queue<int> q;
		q.push(0);
		marked[0] = true;
		while (!q.empty()) {
			act = q.front();
			q.pop();

			for (int v : adyList[act]) {
				if (!marked[v]) {
					marked[v] = true;
					q.push(v);
				}
			}
		}

		if (marked[n + 1]) std::cout << "NO\n";
		else std::cout << "SI\n";

	std::cin >> w;
	}
return 0;
}