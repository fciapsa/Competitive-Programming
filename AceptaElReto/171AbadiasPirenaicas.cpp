#include <iostream>
#include <vector>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;

	std::vector<int> v(n);
	for (int i = 0; i < v.size(); ++i) {
		std::cin >> v[i];
	}
	int max = v[v.size() - 1];
	int cont = 1;
	for (int i = v.size() - 2; i >= 0; --i) {
		if (v[i] > max) {
			max = v[i];
			++cont;
		}
	}
	std::cout << cont << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}