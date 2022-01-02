#include <iostream>
#include <string>
#include <cctype>

int main() {
	int cont1, cont2;
	std::string s;
	getline(std::cin, s);
	while (std::cin) {
		cont1 = 0;
		cont2 = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) ++cont2;
			else if (s[i] == '!') ++cont1;
		}
		if (cont1 > cont2) std::cout << "ESGRITO\n";
		else std::cout << "escrito\n";
	getline(std::cin, s);
	}
return 0;
}