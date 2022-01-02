#include <iostream>

int main() {
	int n, diff = 0, max_diff = 0, cost = 0, open = 0, closed = 0;
	int begin_pos;
	char c;
	std::cin >> n;
	if (n % 2 == 1) {
		for (int i = 0; i < n; ++i) std::cin >> c;
		std::cout << "-1\n";
	}
	else {
		for (int i = 0; i < n; ++i) {
			std::cin >> c;
			if (c == ')') {
				if (diff == 0) begin_pos = i;
				--diff;
				++closed;
			}
			else {
				++diff;
				++open;
			}

			if (diff < max_diff) max_diff = diff;
			if (diff == 0) {
				if (max_diff != 0) cost += (i - begin_pos + 1);
				max_diff = 0;
			}
		}
		if (open == closed) std::cout << cost << '\n';
		else std::cout << "-1\n";
	}
return 0;
}