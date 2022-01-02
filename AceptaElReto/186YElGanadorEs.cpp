#include <iostream>
#include <vector>
#include <string>

int main() {
	int n, g, x, max, winner;
	bool rep;
	std::string dump;
	std::cin >> n >> g;
	while (n != 0) {
		max = 0;
		winner = 1;
		rep = n > 1;
		std::vector<int> v(n);
		for (int i = 0; i < g; ++i) {
			std::cin >> x >> dump;
			++v[x-1];
			if (v[x - 1] > max) {
				rep = false;
				max = v[x - 1];
				winner = x;
			}
			else if (v[x - 1] == max) rep = true;
		}

		if (rep) std::cout << "EMPATE\n";
		else std::cout << winner << '\n';
	std::cin >> n >> g;
	}
return 0;
}