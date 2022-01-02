#include <iostream>
#include <vector>
#include <stack>

int main() {
	int P, C, a, b, act, cont;
	std::cin >> P >> C;
	while (std::cin) {
		if (C >= P - 1) {
			std::vector<std::vector<int>> adyList(P + 1);
			for (int i = 0; i < C; ++i) {
				std::cin >> a >> b;
				adyList[a].push_back(b);
				adyList[b].push_back(a);
			}


			std::vector<bool> marked(P + 1, false);
			std::stack<int> dfs;
			dfs.push(1);
			marked[1] = true;
			cont = 1;
			while (!dfs.empty()) {
				act = dfs.top();
				dfs.pop();

				for (int x : adyList[act]) {
					if (!marked[x]) {
						marked[x] = true;
						dfs.push(x);
						++cont;
					}
				}
			}

			if (cont == P) std::cout << "BICI\n";
			else std::cout << "A PIE\n";
		}
		else {
			for (int i = 0; i < C; ++i) {
				std::cin >> a >> b;
			}
			std::cout << "A PIE\n";
		}

		std::cin >> P >> C;
	}
return 0;
}