#include <iostream>
#include <deque>

bool resuelve() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::deque<int> cola;
	for (int i = 1; i <= N; ++i) cola.push_back(i);

	int M = 2;
	while (cola.size() > M) {
		int cont = 0, hasta = cola.size();
		for (int i = 0; i < hasta; ++i) {
			if (i % M == 0) cola.pop_front();
			else {
				cola.push_back(cola.front());
				cola.pop_front();
			}
		}
	++M;
	}
	if (cola.size() == M) cola.pop_front();

	std::cout << N << ':';
	while (!cola.empty()) {
		std::cout << ' ' << cola.back();
		cola.pop_back();
	}
	std::cout << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}