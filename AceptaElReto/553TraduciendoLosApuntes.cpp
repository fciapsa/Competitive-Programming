#include <iostream>
#include <vector>
#include <algorithm>

struct range {
	int x, y;
	bool operator<(range const& other) const {
		return x < other.x || (x == other.x && y > other.y);
	}
};

int main() {
	int N, x, y, max_R, sol;
	std::cin >> N;
	while (N != 0) {
		std::vector<range> v;
		for (int i = 0; i < N; ++i) {
			std::cin >> x >> y;
			v.push_back({ x,y });
		}

		sort(v.begin(), v.end());
		max_R = 0;
		sol = 0;
		int i = 0;
		while(i < N) {
			if (v[i].y > max_R) {
				if (v[i].x > max_R) {
					sol += v[i].y - v[i].x + 1;
				}
				else sol += v[i].y - max_R;
				max_R = v[i].y;
			}
		++i;
		}
		std::cout << sol << '\n';
	std::cin >> N;
	}
return 0;
}