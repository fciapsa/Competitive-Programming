#include <iostream>

bool resuelve() {
	int N, pos;
	std::cin >> N >> pos;

	if (N == 0 && pos == 0) return false;

	int x, y;
	std::cin >> x >> y;
	while (x != 0 || y != 0) {
		if (x == pos) pos = y;
		else if (y == pos) pos = x;
		std::cin >> x >> y;
	}
	std::cout << pos << '\n';
}

int main() {
	while (resuelve());
	return 0;
}