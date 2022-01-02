#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int c, f, n, act_x, best_x, act_y, best_y, act_distx, best_distx, act_disty, best_disty, greater, lower, k;
	std::cin >> f >> c >> n;
	while (c != 0) {
	std::vector<int> x(n);
	std::vector<int> y(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	act_x = 1;
	best_x = 1;
	lower = 0;
	greater = n;
	act_distx = 0;
	k = 0;
	for (int i = 0; i < n; ++i) act_distx += x[i] - 1;
	best_distx = act_distx;
	while (act_x < f) {
		++act_x;

		while (k < n && x[k] < act_x) {
			++lower;
			--greater;
			++k;
		}

		act_distx += lower;
		act_distx -= greater;

		if (act_distx < best_distx) {
			best_x = act_x;
			best_distx = act_distx;
		}
	}

	act_y = 1;
	best_y = 1;
	lower = 0;
	greater = n;
	act_disty = 0;
	k = 0;
	for (int i = 0; i < n; ++i) act_disty += y[i] - 1;
	best_disty = act_disty;
	while (act_y < c) {
		++act_y;

		while (k < n && y[k] < act_y) {
			++lower;
			--greater;
			++k;
		}

		act_disty += lower;
		act_disty -= greater;

		if (act_disty < best_disty) {
			best_y = act_y;
			best_disty = act_disty;
		}
	}

	std::cout << best_x << ' ' << best_y << '\n';

	std::cin >> f >> c >> n;
	}
return 0;
}