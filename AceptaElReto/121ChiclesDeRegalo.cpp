#include <iostream>

bool resuelve() {
	long long int a, b, n;
	std::cin >> a >> b >> n;

	if (a == 0 && b == 0 && n == 0) return false;

	if (b >= a && n >= a) std::cout << "RUINA\n";
	else {
		if (b > 0) {
			long long int total = n;
			while (n >= a) {
				total += (n / a) * b;
				n = (n % a) + (n / a) * b;
			}
			std::cout << total << ' ' << n << '\n';
		}
		else std::cout << n << ' ' << n << '\n';
	}

return true;
}

int main() {
	while (resuelve());
return 0;
}