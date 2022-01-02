#include <iostream>
#include <climits>

bool resuelve() {
	int dist, n;
	std::cin >> dist >> n;

	if (!std::cin) return false;

	int min = INT_MAX, t, v, aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> t >> v;
		if (t >= 0) {
			aux = dist / v + t;
			if (aux < min) min = aux;
		}
	}

	std::cout << min << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}