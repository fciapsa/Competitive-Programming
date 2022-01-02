#include <iostream>

bool resuelve() {
	long long int n;
	std::cin >> n;

	if (n == 0) return false;

	long long int min = 1, max = n, act;
	while (max > min) {
		act = (min + max + 1) / 2;

		if ((act * (act + 1)) / 2 <= n) min = act;
		else max = act - 1;
	}

	std::cout << max << ' ' << n - ((max * (max + 1)) / 2) << '\n';

	return true;
}

int main() {
	while (resuelve());
	return 0;
}