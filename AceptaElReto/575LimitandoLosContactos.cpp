#include <iostream>
#include <vector>
#include <algorithm>//min
#include <stack>

int index, max;

void tarjan(int v, std::vector<std::vector<int>> const& adyList, std::vector<int>& indexes, std::vector<int>& lowLink,
	std::vector<bool>& onStack, std::stack<int>& p) {

	indexes[v] = index;
	lowLink[v] = index;
	++index;
	p.push(v);
	onStack[v] = true;

	for (int w : adyList[v]) {
		if (indexes[w] == 0) {
			tarjan(w, adyList, indexes, lowLink, onStack, p);
			lowLink[v] = std::min(lowLink[v], lowLink[w]);
		}
		else if (onStack[w]) lowLink[v] = std::min(lowLink[v], indexes[w]);
	}

	if (lowLink[v] == indexes[v]) {
		int cont = 0, x;
		do {
			x = p.top();
			p.pop();
			onStack[x] = false;
			++cont;
		} while (x != v);
		if (cont > max) max = cont;
	}
}

int main() {
	int n, id, k, dest;
	std::cin >> n;
	while (std::cin) {
		std::vector<std::vector<int>> adyList(n + 1);
		std::cin >> id;
		while (id != 0) {
			std::cin >> k;
			while (k--) {
				std::cin >> dest;
				adyList[id].push_back(dest);
			}
			std::cin >> id;
		}

		std::vector<int> indexes(n + 1, 0), lowLink(n + 1);
		std::vector<bool> onStack(n + 1, false);
		std::stack<int> p;
		index = 1;
		max = 1;
		for (int i = 1; i <= n; ++i) {
			if (indexes[i] == 0) tarjan(i, adyList, indexes, lowLink, onStack, p);
		}

		std::cout << max << '\n';
		std::cin >> n;
	}
	return 0;
}