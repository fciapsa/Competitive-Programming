#include <iostream>
#include <vector>
#include <string>

int main() {
	int n, id, aux;
	char op;
	std::cin >> n;
	while (n != 0) {
		std::vector<std::string> mat(n);
		std::cin.ignore();
		for (int i = 0; i < n; ++i) getline(std::cin, mat[i]);

		std::cin >> op;
		while (op != 'x') {
			std::cin >> id;
			if (id > 0) {
				id -= 1;
				if (op == 'f') {
					aux = mat[id][n - 1];
					for (int j = n-1; j > 0; --j) mat[id][j] = mat[id][j - 1];
					mat[id][0] = aux;
				}
				else {
					aux = mat[n - 1][id];
					for (int i = n - 1; i > 0; --i) mat[i][id] = mat[i - 1][id];
					mat[0][id] = aux;
				}
			}
			else {
				id = -id;
				id -= 1;
				if (op == 'f') {
					aux = mat[id][0];
					for (int j = 0; j < n - 1; ++j) mat[id][j] = mat[id][j + 1];
					mat[id][n - 1] = aux;
				}
				else {
					aux = mat[0][id];
					for (int i = 0; i < n - 1; ++i) mat[i][id] = mat[i + 1][id];
					mat[n - 1][id] = aux;
				}
			}
		std::cin >> op;
		}

		for (int i = 0; i < n; ++i) {
			std::cout << mat[i] << '\n';
		}
	    std::cout << "---\n";
	std::cin >> n;
	}
return 0;
}