#include <iostream>
#include <string>

const std::string en = "HELLO", es = "HOLA", de = "HALLO", fr = "BONJOUR", it = "CIAO", ru = "ZDRAVSTVUJTE";

int main() {
	int k = 1;
	std::string s;
	std::cin >> s;
	while (s != "#") {
		std::cout << "Case " << k << ": ";
		if (s == en) std::cout << "ENGLISH\n";
		else if (s == es) std::cout << "SPANISH\n";
		else if (s == de) std::cout << "GERMAN\n";
		else if (s == fr) std::cout << "FRENCH\n";
		else if (s == it) std::cout << "ITALIAN\n";
		else if (s == ru) std::cout << "RUSSIAN\n";
		else std::cout << "UNKNOWN\n";
	++k;
	std::cin >> s;
	}
return 0;
}