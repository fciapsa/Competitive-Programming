#include <iostream>
#include <vector>

int main() {
	int b, n, d, c, x;
	bool ok;
	std::cin >> b >> n;
	while (b != 0) {
		std::vector<int> rv(b+1);
		for (int i = 1; i <= b; ++i) std::cin >> rv[i];

		for (int i = 0; i < n; ++i) {
			std::cin >> d >> c >> x;
			rv[d] -= x;
			rv[c] += x;
		}

		ok = true;
		for (int i = 1; i <= b && ok; ++i)
			ok = rv[i] >= 0;

		if (ok) std::cout << "S\n";
		else std::cout << "N\n";

	std::cin >> b >> n;
	}
return 0;
}