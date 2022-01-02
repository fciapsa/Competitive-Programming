#include <iostream>
#include <string>

int main() {
	int sum, i;
	std::string s;
	getline(std::cin, s);
	while (s != "0") {
		if (s.size() <= 8) {
			sum = 0;
			i = 2;
			while (s.size() >= i) {
				if (i % 2 == 0) sum += (3 * (int(s[s.size()-i]) - int('0')));
				else sum += (int(s[s.size()-i]) - int('0'));
				++i;
			}
			if ((sum + (int(s[s.size() - 1]) - int('0'))) % 10 != 0) std::cout << "NO\n";
			else std::cout << "SI\n";
				
		}
		else {
			sum = 0;
			i = 2;
			while (s.size() >= i) {
				if (i % 2 == 0) sum += (3 * (int(s[s.size()-i]) - int('0')));
				else sum += (int(s[s.size()-i]) - int('0'));
				++i;
			}
			if ((sum + (int(s[s.size() - 1]) - int('0'))) % 10 != 0) std::cout << "NO\n";
			else {
				std::cout << "SI ";
				if (s.size() < 13 || s[0] == '0') std::cout << "EEUU\n";
				else if (s.substr(0, 2) == "50") std::cout << "Inglaterra\n";
				else if (s.substr(0, 2) == "70") std::cout << "Noruega\n";
				else if (s.substr(0, 3) == "380") std::cout << "Bulgaria\n";
				else if (s.substr(0, 3) == "539") std::cout << "Irlanda\n";
				else if (s.substr(0, 3) == "560") std::cout << "Portugal\n";
				else if (s.substr(0, 3) == "759") std::cout << "Venezuela\n";
				else if (s.substr(0, 3) == "850") std::cout << "Cuba\n";
				else if (s.substr(0, 3) == "890") std::cout << "India\n";
				else std::cout << "Desconocido\n";
			}
		}
		getline(std::cin, s);
		}
return 0;
}