#include <iostream>
#include <vector>

const int TAM = 5;

bool sePuede(int val, int k, int const& N,std::vector<int> const& v) {
	if (k == TAM) return val == N;

	if (v[k] != 0 && val % v[k] == 0) return sePuede(val / v[k], k + 1, N, v) || sePuede(val + v[k], k + 1, N, v) || 
		sePuede(val - v[k], k + 1, N, v) || sePuede(val * v[k], k + 1, N, v);
	else return sePuede(val + v[k], k + 1, N, v) ||
		sePuede(val - v[k], k + 1, N, v) || sePuede(val * v[k], k + 1, N, v);
}

int main() {
	int N;
	std::vector<int> v(TAM);
	std::cin >> N;
	while (std::cin) {
		for (int i = 0; i < TAM; ++i) std::cin >> v[i];
		if (sePuede(v[0], 1,N,v)) std::cout << "SI\n";
		else std::cout << "NO\n";

	std::cin >> N;
	}
return 0;
}