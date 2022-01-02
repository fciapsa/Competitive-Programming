#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	int R, S;
	std::string aux;
	std::cin >> R;
	while (R != 0) {
		std::unordered_map<std::string, int> mapa;
		for (int i = 0; i < R; ++i) {
			std::cin >> aux;
			++mapa[aux];
		}
		std::cin >> S;
		for (int i = 0; i < S; ++i) {
			std::cin >> aux;
			std::cout << ++mapa[aux] << '\n';
		}
		std::cout << '\n';

	std::cin >> R;
	}
return 0;
}