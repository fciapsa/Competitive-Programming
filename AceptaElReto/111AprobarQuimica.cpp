#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::string END = "Exit";
const int N_ORB = 19;
const std::vector<int> SIZES = { 2,2,6,2,6,2,10,6,2,10,6,2,14,10,6,2,14,10,6 };
const std::vector<int> LEVELS = { 1,2,2,3,3,4,3,4,5,4,5,6,4,5,6,7,5,6,7 };
const std::vector<char> ORBS = { 's','s','p','s','p','s','d','p','s','d','p','s','f','d','p','s','f','d','p' };

int main() {
	std::string s;
	int n, i, x;
	std::cin >> s;
	while (s != END) {
		std::cin >> n;
		if (n == 0) std::cout << "1s0\n";
		else {
			x = std::min(n, SIZES[0]);
			n -= std::min(n, SIZES[0]);
			if (n == 0) std::cout << LEVELS[0] << ORBS[0] << x;
			else std::cout << LEVELS[0] << ORBS[0] << SIZES[0];
			i = 1;
			while (n != 0) {
				x = std::min(n, SIZES[i]);
				n -= std::min(n, SIZES[i]);
				if (n == 0) std::cout << ' ' << LEVELS[i] << ORBS[i] << x;
				else std::cout << ' ' << LEVELS[i] << ORBS[i] << SIZES[i];
			++i;
			}
			std::cout << '\n';
		}

	std::cin >> s;
	}
return 0;
}