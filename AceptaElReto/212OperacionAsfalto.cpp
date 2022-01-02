#include <iostream>
#include <vector>

bool resuelve() {
	int C;
	std::cin >> C;

	if (C == 0) return false;

	int V, a, b;
	std::cin >> V;
	++V;
	std::vector<int> v(V, 0);
	for (int i = 0; i < C; ++i) {
		std::cin >> a >> b;
		++v[a];
		++v[b];
	}
	int impares = 0;
	for (int i = 1; i < V && impares < 3; ++i) {
		if (v[i] % 2 == 1) ++impares;
	}

	if (impares == 0 || impares == 2) std::cout << "SI\n";
	else std::cout << "NO\n";

return true;
}

int main() {
	while(resuelve());
return 0;
}