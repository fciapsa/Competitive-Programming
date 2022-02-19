#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> v(N);
	std::unordered_map<int, long long int> map;
	for (int i = 0; i < N; ++i) {
		std::cin >> v[i];
		++map[v[i]];
	}

	long long int total = 0;
	for (auto it = map.begin(); it != map.end(); ++it) {
		if (it->second > 1) total += (it->second * (it->second - 1)) / 2;
	}
	for (int i = 0; i < N; ++i) {
		if (map[v[i]] > 1) std::cout << total - map[v[i]] + 1 << '\n';
		else std::cout << total << '\n';
	}

return 0;
}