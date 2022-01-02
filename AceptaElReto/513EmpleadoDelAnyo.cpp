#include <iostream>
#include <vector>

bool resuelve() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<long int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	long int acum = v[0], aux;
	for (int i = 1; i < N; ++i) {
		aux = v[i] * (i + 1) - acum;
		acum += aux;
		v[i] = aux;
	}

	std::cout << v[0];
	for (int i = 1; i < N; ++i) {
		std::cout << ' ' << v[i];
	}

	std::cout << '\n';

	return true;
}

int main() {
	while (resuelve());
	return 0;
}