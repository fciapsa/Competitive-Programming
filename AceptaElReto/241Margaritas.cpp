
#include <iostream>
#include<iomanip>
#include <fstream>

int main() {

	int numCasos = 0, numh = 0, sol = 0;
std::cin >> numCasos;

for (int i = 0; i < numCasos; ++i) {
	std::cin >> numh;
	if (numh > 2 && numh != 5) {
		sol = numh % 3;
		std::cout << sol << '\n';
	}
	else std::cout << "IMPOSIBLE" << '\n';
}
system("PAUSE");
return 0;
}