#include <iostream>

int main() {
	int n, groups, first, act, count, min, max;
	std::cin >> n;
	while (n != 0) {
		groups = 1;
		count = 1;
		min = n;
		max = 1;
		std::cin >> first;
		for (int i = 1; i < n; ++i) {
			std::cin >> act;
			if (act < first) {
				if (count < min) min = count;
				if (count > max) max = count;
				first = act;
				count = 1;
				++groups;
			}
			else ++count;
		}
		if (count < min) min = count;
		if (count > max) max = count;
		std::cout << groups << ' ' << min << ' ' << max << '\n';
	std::cin >> n;
	}
return 0;
}