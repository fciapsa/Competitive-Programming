#include <iostream>
#include <string>

int main() {
	int n; std::string nb;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> nb >> nb;
		std::cout << "Hola, " << nb << ".\n";
	}
return 0;
}