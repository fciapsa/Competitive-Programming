#include <iostream>
#include <vector>
#include <string>

const std::string S = "==X== ";

int main() {
	int x, carry, aux, pot;
	std::cin >> x;
	while (std::cin) {
		std::vector<int> izq, der, b3;
		while (x > 2) {
			b3.push_back(x % 3);
			x /= 3;
		}
		b3.push_back(x);

		carry = 0;
		pot = 1;
		for (int i = 0; i < b3.size(); ++i) {
			aux = b3[i] + carry;
			switch (aux) {
			case 0: break;
			case 1: carry = 0;
				izq.push_back(pot); break;
			case 2: der.push_back(pot);
				carry = 1; break;
			case 3: carry = 1; break;
			}

			pot *= 3;
		}

		if (carry == 1) izq.push_back(pot);

		for (int i = 0; i < izq.size(); ++i) std::cout << izq[i] << ' ';
		std::cout << S;
		for (int i = 0; i < der.size(); ++i) std::cout << der[i] << ' ';
		std::cout << "patatas\n";

	std::cin >> x;
	}
return 0;
}