#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string s;
	int n, x, y, tam;
	getline(std::cin, s);
	std::cin >> n;
	while (n != 0) {
		tam = s.size();
		std::vector<int> v(tam);
		for (int i = 1; i < tam; ++i) {
			if (s[i] == s[i - 1]) v[i] = v[i - 1];
			else v[i] = v[i - 1] + 1;
		}

		for (int i = 0; i < n; ++i) {
			std::cin >> x >> y;
			if (v[x] == v[y]) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
		std::cout << '\n';
	std::cin.ignore();
	getline(std::cin, s);
	std::cin >> n;
	}

return 0;
}