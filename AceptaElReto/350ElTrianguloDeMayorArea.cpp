#include <iostream>
#include <iomanip>

int main() {
	int a;
	float b;
	std::cin >> a >> b;
	while (a != 0) {
		std::cout << std::fixed << std::setprecision(1) << a * b / 2 << '\n';
	std::cin >> a >> b;
	}
return 0;
}