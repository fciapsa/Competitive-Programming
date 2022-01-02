#include <iostream>
#include <vector>
#include <algorithm>

using llint = long long int;
std::vector<llint> pots;
std::vector<std::vector<llint>> numComb(64, std::vector<llint>(5, 0));

llint hasta(llint num, int luces) {
	if (num == -1) return 0;

	int sub_pot = 0;
	while (pots[sub_pot + 1] <= num) ++sub_pot;

	int aux = 0;
	for (int i = 0; i <= luces; ++i) aux += numComb[sub_pot][i];

	if (num == pots[sub_pot]) return aux;
	num -= pots[sub_pot];
	return aux + hasta(num-1, std::min(luces - 1, sub_pot - 1));
}

bool resuelve() {
	llint n, a, b;
	std::cin >> n >> a >> b;

	if (n == 0 && a == 0 && b == 0) return false;

	std::cout << hasta(b, n) - hasta(a - 1, n) << '\n';

return true;
}

int main() {
	llint pot = 1;
	for (int i = 0; i < 64; ++i) {
		pots.push_back(pot - 1);
		pot *= 2;
	}
	numComb[0][0] = 1;
	for (int i = 1; i < 64; ++i) {
		numComb[i][0] = 1;
		for (int j = 1; j < 5; ++j) {
			numComb[i][j] = numComb[i - 1][j - 1] + numComb[i - 1][j];
		}
	}
	while (resuelve());
return 0;
}