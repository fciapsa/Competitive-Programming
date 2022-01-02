#include <iostream>
#include <string>
#include <vector>

int main() {
	int T, x1, x2, carry, i1, i2, aux;
	std::string n1, n2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n1 >> n2;
		i1 = n1.size() - 1;
		i2 = n2.size() - 1;

		std::vector<int> sol;
		carry = 0;
		while (i1 >= 0 && i2 >= 0) {
			x1 = int(n1[i1]) - int('0');
			x2 = int(n2[i2]) - int('0');
			aux = x1 * x2 + carry;
			sol.push_back(aux % 10);
			carry = aux / 10;

			--i1;
			--i2;
		}

		if (carry > 0) {
			sol.push_back(carry);
			--i1;
			--i2;
		}
		while (i1 >= 0) {
			sol.push_back(0);
			--i1;
		}
		while (i2 >= 0) {
			sol.push_back(0);
			--i2;
		}

		for (int i = sol.size() - 1; i >= 0; --i) std::cout << sol[i];
		std::cout << '\n';
	}
return 0;
}