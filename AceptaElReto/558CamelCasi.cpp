#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cctype>

int main() {
	int n, mayus;
	std::string aux;
	std::cin >> n;
	while (std::cin) {
		std::vector<std::string> palabras(n);
		std::vector<std::string> lowers(n);
		std::unordered_map<std::string, std::pair<int, int>> map;
		for (int i = 0; i < n; ++i) {
			std::cin >> palabras[i];
			aux = palabras[i];
			mayus = 0;
			for (int j = 0; j < aux.size(); ++j) {
				if (isupper(aux[j])) {
					++mayus;
					aux[j] = char(tolower(aux[j]));
				}
			}
			lowers[i] = aux;
			if (map.count(aux) > 0) {
				if (map[aux].first < mayus) map[aux] = { mayus,i };
			}
			else map[aux] = { mayus,i };
		}


		for (int i = 0; i < n; ++i) {
			std::cout << palabras[map[lowers[i]].second] << '\n';
		}

		std::cout << "---\n";
	std::cin >> n;
	}
return 0;
}