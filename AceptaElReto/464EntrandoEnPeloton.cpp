#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
	int N, hh, mm, ss, pos;
	char c;
	std::cin >> N;
	while (std::cin) {
		std::vector<int> v1(N), v2(N);
		std::unordered_map<int, int> map;

		for (int i = 0; i < N; ++i) {
			std::cin >> hh >> c >> mm >> c >> ss;
			v1[i] = 3600 * hh + 60 * mm + ss;
			v2[i] = v1[i];
		}

		sort(v2.begin(), v2.end());
		map[v2[0]] = 1;
		pos = 1;
		for (int i = 1; i < N; ++i) {
			if (v2[i] - v2[i - 1] > 1) pos = i + 1;
			map[v2[i]] = pos;
		}

		for (int i = 0; i < N; ++i) std::cout << map[v1[i]] << '\n';
		std::cout << "---\n";

	std::cin >> N;
	}
return 0;
}