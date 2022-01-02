#include <iostream>
#include <string>

const std::string END = "FIN";

int main() {
	std::string s;
	getline(std::cin, s);
	while (s != END) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ') {
				if (s[i] != 'Z') ++s[i];
				else s[i] = 'A';
			}
		}
		std::cout << s << '\n';
	getline(std::cin, s);
	}
return 0;
}