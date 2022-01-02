#include <iostream>
#include <vector>

int main() {
	int t, w, y1, y2, k = 0, cmp;
	bool ok;
	std::cin >> t;
	while (t--) {
		std::cin >> w;
		std::vector<int> gaps(w);
		for (int i = 0; i < w; ++i) {
			std::cin >> y1 >> y2;
			gaps[i] = y2 - y1;
		}

		cmp = gaps[0];
		ok = true;
		for (int i = 1; i < w && ok; ++i) {
			ok = gaps[i] == cmp;
		}

		if (k != 0) std::cout << '\n';
		if (ok) std::cout << "yes\n";
		else std::cout << "no\n";
		++k;
	}
return 0;
}