#include <iostream>
#include <vector>
#include <algorithm>

struct compra {
	int id, precio;
	bool operator<(compra const& other) const {
		return precio < other.precio;
	}
};

int main() {
	int N, T, C, i, j, sol;
	std::cin >> N;
	while (N != 0) {
		std::cin >> C >> T;
		std::vector<int> v1(N), v2(N);
		for (int i = 0; i < N; ++i) std::cin >> v1[i];
		for (int i = 0; i < N; ++i) std::cin >> v2[i];

		std::vector<compra> dif1(N), dif2(N);
		for (int i = 0; i < N; ++i) {
			dif1[i] = { i,v1[i] - v2[i] };
		}
		for (int i = 0; i < N; ++i) {
			dif2[i] = { i,v2[i] - v1[i] };
		}

		sort(dif1.begin(), dif1.end());
		sort(dif2.begin(), dif2.end());
		std::vector<bool> marked(N, false);
		i = 0;
		j = 0;
		sol = 0;
		while (C > 0 && T > 0) {
			while (marked[dif1[i].id]) ++i;
			while (marked[dif2[j].id]) ++j;

			if (dif1[i] < dif2[j]) {
				--C;
				sol += v1[dif1[i].id];
				marked[dif1[i].id] = true;
				++i;
			}
			else {
				--T;
				sol += v2[dif2[j].id];
				marked[dif2[j].id] = true;
				++j;
			}
		}
		while (C > 0) {
			while (marked[dif1[i].id]) ++i;

			--C;
			sol += v1[dif1[i].id];
			marked[dif1[i].id] = true;
			++i;
		}
		while (T > 0) {
			while (marked[dif2[j].id]) ++j;

			--T;
			sol += v2[dif2[j].id];
			marked[dif2[j].id] = true;
			++j;
		}

		for (int i = 0; i < N; ++i) {
			if (!marked[i]) {
				if (v1[i] < v2[i]) sol += v1[i];
				else sol += v2[i];
			}
		}

		std::cout << sol << '\n';

		std::cin >> N;
	}
return 0;
}