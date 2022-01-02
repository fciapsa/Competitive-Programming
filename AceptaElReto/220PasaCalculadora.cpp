#include <iostream>

const int MAX = 31;

bool miTurno(int sum, int x, int y, bool &yoGano) {
	if (sum == 30) return false;
	else {
		yoGano = false;
		for (int i = 0; i < 3 && !yoGano; ++i) {
			if (i != x && sum + i * 3 + y + 1 < MAX) {
				int xa = i;
				yoGano = !miTurno(sum + i * 3 + y + 1, xa, y, yoGano);
			}
		}

		for (int j = 0; j < 3 && !yoGano; ++j) {
			if (j != y && sum + x * 3 + j + 1 < MAX) {
				int ya = j;
				yoGano = !miTurno(sum + x * 3 + j + 1, x, ya, yoGano);
			}
		}
		return yoGano;
	}
}

int main() {
	int nc;
	std::cin >> nc;
	int sum, n;
	int x, y;
	for (int i = 0; i < nc; ++i) {
		std::cin >> sum >> n;

		if (sum == 31) std::cout << "GANA\n";
		else {
			if (n % 3 == 1) y = 0;
			else if (n % 3 == 2) y = 1;
			else y = 2;

			if (n <= 3) x = 0;
			else if (n <= 6) x = 1;
			else x = 2;

			bool yoGano = miTurno(sum, x, y, yoGano);
			if (yoGano) std::cout << "GANA\n";
			else std::cout << "PIERDE\n";
		}
	}

	return 0;
}