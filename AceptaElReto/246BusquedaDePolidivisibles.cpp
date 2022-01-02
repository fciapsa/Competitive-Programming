#include <iostream>

void poli(long long int N, int D, int numDig) {
	if (numDig == D && (N % numDig == 0)) std::cout << N << '\n';
	else {
		if (N % numDig == 0) {
			std::cout << N << '\n';
			for (int i = 0; i < 10; ++i) {
				long long int N2 = N * 10 + i;
				poli(N2, D, numDig + 1);
			}
		}
	}
}

void escribePolidivisibles(long long int N, int D) {
	int numDig = 1; long long int aux = N;
	while (aux / 10 > 0) {
		++numDig;
		aux /= 10;
	}
	poli(N, D, numDig);
}

bool resuelveCaso() {
	long long int N;
	int D;
	std::cin >> N >> D;

	if (!std::cin) return false;

	escribePolidivisibles(N, D);
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}