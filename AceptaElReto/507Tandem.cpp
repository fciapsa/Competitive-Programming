#include <iostream>
#include <algorithm>
#include <vector>

bool resuelveCaso() {
	int N, max;
	std::cin >> N >> max;

	if (N == 0 && max == 0) return false;

	std::vector<int> pes(N);
	for (int i = 0; i < N; ++i) std::cin >> pes[i];

	sort(pes.begin(), pes.end());

	int q = pes.size() - 1;
	long long int cont = 0;
	for (int i = 0; q > i; ++i) {
		while (q > i && pes[i] + pes[q] > max) --q;
		if (q > i) cont += q - i;
	}

	std::cout << cont << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}