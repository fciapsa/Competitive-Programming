#include <iostream>
#include <vector>

int main() {
	int N, hasta, k;
	bool ok;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> v(N);
		for (int i = 0; i < N; ++i) std::cin >> v[i];
		hasta = N - 1;
		for (int i = 0; i < hasta; ++i) {
			v[i] = v[i + 1] - v[i];
		}

		ok = false;
		k = 1;
		while(!ok) {
			ok = true;
			for (int i = k; i < hasta && ok; ++i) {
				ok = v[i] == v[i % k];
			}
		if(!ok) ++k;
		}
		
		std::cout << v[hasta] + v[hasta % k] << '\n';

	std::cin >> N;
	}
return 0;
}