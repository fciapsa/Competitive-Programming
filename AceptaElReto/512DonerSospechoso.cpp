#include <iostream>
#include <cmath>

int main() {
	int nc;
	std::cin >> nc;
	int cab, con;
	for (int i = 0; i < nc; ++i) {
		std::cin >> con >> cab;
		std::cout << std::floor((100 * con / (cab + con))) << '\n';
	}
	return 0;
}