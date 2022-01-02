#include <iostream>

long int paj(long int x, long int y) {
	long int min, max;
	if (x < y) {
		min = x;
		max = y;
	}
	else {
		min = y;
		max = x;
	}
	if (x < 10 || y < 10) return 0;
	else if (x == y) return 1;
	else return max / min + paj(max - (max / min)*min, min);

}

int main() {
	long int x, y;
	std::cin >> x >> y;
	while (x != 0 && y != 0) {

		std::cout << paj(x, y) << '\n';
		std::cin >> x >> y;
	}

	return 0;
}