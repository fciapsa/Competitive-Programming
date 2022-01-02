#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

int main() {
	std::string ap, nomb;
	int T, cont, tot;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::unordered_map<std::string, int> map;
		cont = 0;
		tot = 0;
		std::cin >> ap;
		while (ap != "====") {
			++tot;
			std::cin >> nomb;
			for (int i = 0; i < ap.size(); ++i) {
				if (isupper(ap[i])) ap[i] = char(tolower(ap[i]));
			}
			++map[ap];
			if (map[ap] > 2) ++cont;
			else if (map[ap] == 2) cont += 2;
			std::cin >> ap;
		}

		std::cout << tot << ' ' << cont << '\n';
	}
return 0;
}