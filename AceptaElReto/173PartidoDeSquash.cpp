#include <iostream>
#include <string>
#include <cmath>

const int WIN = 9, MIN_DIFF = 2;

int main() {
	int a, b, i, lastWin;
	char winner;
	bool first, afterWin;
	std::string s;
	std::cin >> s;
	while (s != "F") {
		first = true;
		winner = 'A';
		afterWin = true;
		lastWin = -1;
		a = 0;
		b = 0;
		i = 0;
		while (s[i] != 'F') {
			if (afterWin) {
				afterWin = false;
				if (s[i] == winner) {
					if (winner == 'A') a = 1;
					else b = 1;
				}
			}
			else {
				if (s[i] == s[i - 1]) {
					if (s[i] == 'A') ++a;
					else ++b;
				}

				if ((a >= WIN || b >= WIN) && std::abs(a - b) >= MIN_DIFF) {
					if (a > b) winner = 'A';
					else winner = 'B';
					lastWin = i;
					afterWin = true;

					if (first) {
						first = false;
						std::cout << a << '-' << b;
					}
					else std::cout << ' ' << a << '-' << b;

					a = 0;
					b = 0;
				}
			}
		++i;
		}
		if (lastWin < int(s.size()) - 2) {
			if (first) std::cout << a << '-' << b;
			else std::cout << ' ' << a << '-' << b;
		}
		std::cout << '\n';
	std::cin >> s;
	}

return 0;
}