#include <iostream>
#include <vector>

int main() {
	int T, aux;
	std::vector<int> v(6);
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		for (int i = 0; i < 6; ++i) std::cin >> v[i];
		for (int i = 0; i < 6; ++i) {
			std::cin >> aux;
			v[i] += aux;
		}

		if (v[1] == v[0] && v[2] == v[0] && v[3] == v[0] && v[4] == v[0] && v[5] == v[0]) std::cout << "SI\n";
		else std::cout << "NO\n";
	}

return 0;
}