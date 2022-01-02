#include <iostream>
#include <vector>

int main() {
	int p, a, x1, x2, k, dif;
	bool f1, f2;
	std::cin >> p >> a;
	while (p != 0) {
		std::vector<bool> gives(p + 1, false), receives(p + 1, false);
		for (int i = 0; i < a; ++i) {
			std::cin >> x1 >> x2;
			gives[x1] = true;
			receives[x2] = true;
		}

		dif = p - a;
		if (dif > 2) std::cout << "NO\n";
		else if (dif < 2) std::cout << "SI\n";
		else {
			f1 = false;
			f2 = false;
			k = 1;
			while (!f1) {
				if (!gives[k]) {
					x1 = k;
					f1 = true;
				}
				++k;
			}
			while (!f2) {
				if (!gives[k]) {
					x2 = k;
					f2 = true;
				}
				++k;
			}

			if (receives[x1] && receives[x2]) std::cout << "NO\n";
			else std::cout << "SI\n";
		}

		std::cin >> p >> a;
	}
return 0;
}