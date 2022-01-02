#include <iomanip>
#include <iostream>

int main() {
	int dd = 0, em = 0, D = 0, HH = 0, MM = 0, SS = 0, sstotal = 0;
	std::cin >> dd >> em;

	while (dd != 0 || em != 0) {
	sstotal = 6 * 24 * dd*em;
	D = sstotal / 86400;
	HH = (sstotal % 86400) / 3600;
	MM = ((sstotal % 86400) % 3600) / 60;
	SS = ((sstotal % 86400) % 3600) % 60;
	std::cout << D << ':';
	std::cout << std::setw(2) << std::setfill('0') << HH << ':';
	std::cout << std::setw(2) << std::setfill('0') << MM << ':';
	std::cout << std::setw(2) << std::setfill('0') << SS << '\n';
		std::cin >> dd >> em;
	}

system("PAUSE");
return 0;
}