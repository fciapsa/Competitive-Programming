#include <iostream>

int main() {
	int numCasos = 0, N = 0, M = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		std::cin >> N >> M;
		int rang = (((N + M + 1)*(N + M + 2))/2) - M;
		std::cout << rang << '\n';
	}
return 0;
}