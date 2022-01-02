#include <iostream>
#include <deque>

int main() {
	int b, p;

	std::cin >> b >> p;
	while (b != 0 || p != 0) {
		std::deque<int> cola;
		for (int i = 1; i <= b; ++i) {
			cola.push_back(i);
		}

		while (cola.size() > 1) {
			for (int j = 1; j < p; ++j) {
				cola.push_back(cola.front());
				cola.pop_front();
			}
			cola.pop_front();
		}

		std::cout << cola.front() << '\n';
		std::cin >> b >> p;
	}

return 0;
}