#include <iostream>
#include <string>
#include <algorithm>

char T[4001];
int P[4001];

int main() {
	std::string s;
	std::cin >> s;
	while (std::cin) {
		int tam = 2 * s.size() + 1, C = 0, R = -1, rad, max = 1;
		T[0] = '#';
		for (int i = 1, j = 0; i < tam; i += 2, ++j) {
			T[i] = s[j];
			T[i + 1] = '#';
		}
		for (int i = 0; i < tam; ++i) {
			if (i < R) rad = std::min(P[2 * C - i], R - i);
			else rad = 0;
			while (i + rad + 1 < tam && i - rad - 1 >= 0 && T[i + rad + 1] == T[i - rad - 1]) ++rad;
			P[i] = rad;
			if (rad > max) max = rad;
			if (i + rad > R) {
				C = i;
				R = i + rad;
			}
		}
		std::cout << max << '\n';

	std::cin >> s;
	}
return 0;
}