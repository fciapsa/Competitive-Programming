#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> pos, neg;
	std::vector<bool> v(N);

	int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		if (aux > 0) {
			pos.push_back(aux);
			v[i] = true;
		}
		else {
			neg.push_back(aux);
			v[i] = false;
		}
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(),std::greater<int>());

	int j = 0, k = 0;
	if (v[0]) {
		std::cout << pos[j];
		++j;
	}
	else {
		std::cout << neg[k];
		++k;
	}

	for (int i = 1; i < N; ++i) {
		if (v[i]) {
			std::cout << ' ' << pos[j];
			++j;
		}
		else {
			std::cout << ' ' << neg[k];
			++k;
		}
	}

	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}