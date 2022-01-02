#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string s;
	int aux;
	getline(std::cin, s);
	while (std::cin) {
		std::vector<char> v;
		int i = 0;
		while (i < s.size()) {
			if (s[i] == '1') {
				aux = 100 + 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
				v.push_back(char(aux));
				i += 3;
			}
			else {
				aux = 10 * (s[i] - '0') + (s[i + 1] - '0');
				v.push_back(char(aux));
				i += 2;
			}
		}

		for (int i = 0; i < v.size(); ++i) std::cout << v[i];
		std::cout << '\n';

	getline(std::cin, s);
	}
return 0;
}