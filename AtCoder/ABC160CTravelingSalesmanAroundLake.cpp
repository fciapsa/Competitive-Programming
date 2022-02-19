#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int K, N;
	std::cin >> K >> N;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];
	sort(v.begin(), v.end());

	int ini = v[0], fin = K - v[N - 1];
	int max = v[0];
	for (int i = 1; i < N; ++i) {
		if (v[i] - v[i - 1] > max) max = v[i] - v[i - 1];
	}
	if (K - v[N - 1] > max) max = K - v[N - 1];
	if (ini + fin > max) max = ini + fin;

	std::cout << K - max << '\n';
return 0;
}