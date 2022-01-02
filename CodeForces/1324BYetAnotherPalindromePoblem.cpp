#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
	int T, n, ant, act, k;
	bool found;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> n;
		found = false;
		std::unordered_map<int, int> map;
		std::cin >> ant;
		++map[ant];
		std::cin >> ant >> act;
		++map[ant];
		++map[act];
		if (map[act] > 2 || (map[act] == 2 && act != ant)) found = true;
		k = 3;
		while(k < n && !found) {
			ant = act;
			std::cin >> act;
			++map[act];
			if (map[act] > 2 || (map[act] == 2 && act != ant)) found = true;
		++k;
		}
		while (k < n) {
			std::cin >> act;
			++k;
		}
		if (found) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
return  0;
}