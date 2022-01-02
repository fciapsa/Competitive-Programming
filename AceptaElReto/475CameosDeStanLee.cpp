#include <iostream>
#include <string>

const std::string N = "stanlee";

int main() {
	std::string s;
	int T, k, cont;
	std::cin >> T;
	std::cin.ignore();
	for (int t = 0; t < T; ++t) {
		getline(std::cin, s);
		k = 0;
		cont = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (tolower(s[i]) == N[k]) ++k;
			if (k == 7) {
				k = 0;
				++cont;
			}
		}

		std::cout << cont << '\n';
	}
return 0;
}