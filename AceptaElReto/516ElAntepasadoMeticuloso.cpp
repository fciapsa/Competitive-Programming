#include <iostream>
#include <vector>

int main() {
	int T, L, N, sol, act, k, next;
	bool ok;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> L >> N;
		std::vector<int> v(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> v[i];
			++v[i];
		}

		ok = false;
		sol = L;
		while (!ok && sol > 0) {
			ok = true;
			k = 0;
			act = 0;
			while (k < N && ok) {
				next = act + v[k];
				if (next < sol) {
					act = next;
					++k;
				}
				else if (next == sol) {
					if (k != N - 1) ok = false;
					else ++k;
				}
				else if (next == sol + 1) {
					act = 0;
					++k;
				}
				else ok = false;
			}

			if (!ok) --sol;
		}

		if (sol == 0) std::cout << "IMPOSIBLE\n";
		else std::cout << sol << '\n';
	}
	return 0;
}