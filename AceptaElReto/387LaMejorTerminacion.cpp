#include <iostream>
#include <vector>

int main() {
	int n, max, vmax, x;
	bool rep;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(10);
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			++v[x % 10];
		}

		vmax = v[0];
		max = 0;
		rep = false;
		for (int i = 1; i < 10; ++i) {
			if (v[i] > vmax) {
				rep = false;
				max = i;
				vmax = v[i];
			}
			else if (v[i] == vmax) rep = true;
		}

		if (rep) std::cout << "VARIAS\n";
		else std::cout << max << '\n';

	std::cin >> n;
	}
return 0;
}