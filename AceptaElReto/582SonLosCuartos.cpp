#include <iostream>
#include <string>

int main() {
	int t;
	std::string s;
	std::cin >> t;
	std::cin.ignore();
	while (t--) {
		getline(std::cin, s);
		if (s.size() == 0) std::cout << "MARISA NARANJO\n";
		else if (s.size() < 71) std::cout << "TARDE\n";
		else if (s.size() == 71) std::cout << "CORRECTO\n";
		else std::cout << "SALIDA NULA\n";
	}
return 0;
}