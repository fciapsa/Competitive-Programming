#include <iostream>
#include <iomanip>
#include <iostream>


int main() {
	int numCasos = 0; int numg = 0;
	int HH = 0, MM = 0, SS = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		std::cin >> numg;
		HH = numg / 3600;
		MM = (numg % 3600) / 60;
		SS = (numg % 3600) % 60;
		std::cout << std::setfill('0') << std::setw(2) << HH << ':';
		std::cout << std::setfill('0') << std::setw(2) << MM << ':';
		std::cout << std::setfill('0') << std::setw(2) << SS << '\n';
	}
	system("PAUSE");
	return 0;
}