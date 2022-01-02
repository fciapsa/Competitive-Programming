#include <iostream>

int main() {
	int p1, b1, l1, p2, b2, l2, sol1, sol2;
	bool impos1, impos2;
	std::cin >> p1 >> b1 >> l1 >> p2 >> b2 >> l2;
	while (p1 != 0 && p2 != 0) {
		impos1 = false;
		impos2 = false;
		if (b1 >= p1) sol1 = 1;
		else if (l1 >= b1) impos1 = true;
		else {
			sol1 = 1 + (p1 - b1) / (b1-l1);
			if ((p1 - b1) % (b1 - l1) != 0) ++sol1;
		}
		if (b2 >= p2) sol2 = 1;
		else if (l2 >= b2) impos2 = true;
		else {
			sol2 = 1 + (p2 - b2) / (b2 - l2);
			if ((p2 - b2) % (b2 - l2) != 0) ++sol2;
		}

		if (impos1) std::cout << "VECINO " << sol2 << '\n';
		else if (impos2) std::cout << "YO " << sol1 << '\n';
		else if (sol1 < sol2) std::cout << "YO " << sol1 << '\n';
		else if (sol2 < sol1) std::cout << "VECINO " << sol2 << '\n';
		else std::cout << "EMPATE " << sol1 << '\n';

	std::cin >> p1 >> b1 >> l1 >> p2 >> b2 >> l2;
	}
return 0;
}