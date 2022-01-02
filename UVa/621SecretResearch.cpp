#include <iostream>
#include <string>

int main() {
	std::string s;
	int n, tam;
	std::cin >> n;
	while (n--) {
		std::cin >> s;
		tam = s.size() - 1;
		if (tam >= 1) {
			if (s[tam - 1] == '3' && s[tam] == '5') std::cout << "-\n";
			else if (s[0] == '9' && s[tam] == '4') std::cout << "*\n";
			else if (tam > 1 && s[0] == '1' && s[1] == '9' && s[2] == '0') std::cout << "?\n";
			else std::cout << "+\n";
		}
		else std::cout << "+\n";
	}
return 0;
}