#include <iostream>
#include <queue>

int main() {
	int n, c;
	std::cin >> n >> c;
	while (n != 0) {
		std::queue<int> cola;
		for (int i = 1; i <= n; ++i)cola.push(i);

		while (cola.size() > 1) {
			for (int i = 0; i < c; ++i) {
				cola.push(cola.front());
				cola.pop();
			}
			cola.pop();
		}

		std::cout << cola.front() << '\n';
	std::cin >> n >> c;
	}
return 0;
}