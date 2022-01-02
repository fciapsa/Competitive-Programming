#include <iostream>
#include <queue>

int main() {
	int f, L, cortes;
	std::cin >> f >> L;
	while (f != 0) {
		cortes = 0;
		f *= 2;
		std::queue<int> q;
		q.push(L);
		while (!q.empty()) {
			L = q.front();
			q.pop();
			if (L > f) {
				++cortes;
				q.push(2 * (L / 3) + L % 3);
				q.push(L / 3);
			}
		}
		std::cout << cortes << '\n';

	std::cin >> f >> L;
	}
return 0;
}