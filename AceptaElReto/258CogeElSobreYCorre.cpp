#include <iostream>
#include <deque>

bool resuelveCaso() {
	int N, k;
	std::cin >> N >> k;

	if (N == 0) return false;

	if (k > 1) {

		std::deque<int> cola, aux;
		int ind = 0, max = 0, x;

		while (ind < k) {
			std::cin >> x;
			cola.push_back(x);

			if (x > max) {
				max = x;
				aux.clear();
			}
			else {
				while (!aux.empty() && x > aux.back()) aux.pop_back();
				aux.push_back(x);
			}
			++ind;
		}
		std::cout << max;//primer caso

		while (ind < N) {
			std::cin >> x;
			cola.push_back(x);

			if (max == cola.front()) {
				max = aux.front();
				aux.pop_front();
			}
			cola.pop_front();

			if (x > max) {
				max = x;
				aux.clear();
			}
			else {
				while (!aux.empty() && x > aux.back()) aux.pop_back();
				aux.push_back(x);
			}

			std::cout << ' ' << max;

			++ind;
		}
	}

	else {
		int x;
		std::cin >> x;
		std::cout << x;
		for (int i = 1; i < N; ++i) {
			std::cin >> x;
			std::cout << ' ' << x;
		}
	}

	std::cout << '\n';
return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelveCaso());
	return 0;
}