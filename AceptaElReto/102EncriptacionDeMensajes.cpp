#include <iostream>
#include <string>
#include <cctype>

const std::string END = "FIN";

int main() {
	int cont;
	char p;
	std::string s;
	std::cin.get(p);
	getline(std::cin, s);
	int cte;
	if (p >= 'p') cte = 26-(int(p) - int('p'));
	else cte = 26-(int(p) - 86);
	if (cte == 26) cte = 0;
	if (cte != 0) {
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) {
				if (islower(s[i])) {
					if (int(s[i]) + cte <= int('z')) s[i] = char(int(s[i]) + cte);
					else s[i] = char(int('a') + (int(s[i]) + cte - 123));
				}
				else {
					if (int(s[i]) + cte <= int('Z')) s[i] = char(int(s[i]) + cte);
					else s[i] = char(int('A') + (int(s[i]) + cte - 91));
				}
			}
		}
	}
	cont = 0;
	if (s != END) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' ||
				s[i] == 'I' || s[i] == 'O' || s[i] == 'U') ++cont;
		}
		std::cout << cont << '\n';
	}
	while (s != END) {
		std::cin.get(p);
		getline(std::cin, s);
		if (p >= 'p') cte = 26-(int(p) - int('p'));
		else cte = 26 - (int(p) - 86);
		if (cte == 26) cte = 0;
		if (cte != 0) {
			for (int i = 0; i < s.size(); ++i) {
				if (isalpha(s[i])) {
					if (islower(s[i])) {
						if (int(s[i]) + cte <= int('z')) s[i] = char(int(s[i]) + cte);
						else s[i] = char(int('a') + (s[i] + cte - 123));
					}
					else {
						if (int(s[i]) + cte <= int('Z')) s[i] = char(int(s[i]) + cte);
						else s[i] = char(int('A') + (int(s[i]) + cte - 91));
					}
				}
			}
		}
		cont = 0;
		if (s != END) {
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' ||
					s[i] == 'I' || s[i] == 'O' || s[i] == 'U') ++cont;
			}
			std::cout << cont << '\n';
		}
	}
return 0;
}