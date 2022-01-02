#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, area = 0;

	std::cin >> x1 >> y1 >> x2 >> y2;
		while (x1 <= x2 && y1 <= y2) {
			area = (x2 - x1)*(y2 - y1);
			std::cout << area << '\n';
			std::cin >> x1 >> y1 >> x2 >> y2;
		}

system("PAUSE");
return 0;
}