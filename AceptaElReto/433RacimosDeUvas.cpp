#include <iostream>

bool resuelve() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	int i = 1;
	while (N > 0) {
		N -= i;
		++i;
	}

	std::cout << i-1 << '\n';
return true;
}

int main() {
	while (resuelve());
return 0;
}