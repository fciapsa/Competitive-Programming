#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> v(N), w;
		for (int i = 0; i < N; ++i) std::cin >> v[i];

		w = v;
		sort(w.begin(), w.end());
		int i = 0;
		for (int j = 0; j < N; ++j) {
			if (w[i] == v[j]) ++i;
		}
		std::cout << N - i << '\n';

	std::cin >> N;
	}
return 0;
}