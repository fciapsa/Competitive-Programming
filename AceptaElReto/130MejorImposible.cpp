#include <iostream>
#include <cstdlib>

int main() {
	int tam, x1, y1, x2, y2;
	std::cin >> tam;

	while (tam != 0) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2) std::cout << "0\n";
		else if (abs(x1 - x2) == abs(y1 - y2)) std::cout << "1\n";
		else if (abs(x1 - x2) % 2 == abs(y1 - y2) % 2) std::cout << "2\n";
		else std::cout << "IMPOSIBLE\n";
	
	std::cin >> tam;
	}
return 0;
}