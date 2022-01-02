#include <iostream>
#include <vector>

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;

	std::vector<bool> v(n+1, false);
	int x;
	for (int i = 0; i < v.size() - 2; ++i) {
		std::cin >> x;
		v[x] = true;
	}
	bool b = false;
	for (int i = 1; i < v.size() && !b; ++i) {
		if (!v[i]) { 
			std::cout << i << '\n';
			b = true;
		}
	}
	return true;
}

int main() {
	while (resuelveCaso());
return 0;
}