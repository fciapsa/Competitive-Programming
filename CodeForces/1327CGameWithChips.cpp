#include <iostream>
#include <vector>

int main() {
	int n, m, k, dump;
	std::cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) std::cin >> dump >> dump;
	for (int i = 0; i < k; ++i) std::cin >> dump >> dump;

	//Como el limite es hasta 2*n*m, siempre entra la solucion de llevar todas las fichas a una esquina y de ahi moverse
	//por todo el tablero... :(
	std::vector<char> v;
	for (int i = 0; i < m - 1; ++i) v.push_back('L');
	for (int i = 0; i < n - 1; ++i) v.push_back('U');
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 1; j < m; ++j) v.push_back('R');
		}
		else {
			for (int j = 1; j < m; ++j) v.push_back('L');
		}
		if (i < n - 1) v.push_back('D');
	}
	std::cout << v.size() << '\n';
	for (int i = 0; i < v.size(); ++i) std::cout << v[i];
	std::cout << '\n';
return 0;
}