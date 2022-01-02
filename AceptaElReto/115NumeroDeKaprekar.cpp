#include <iostream>

int main() {
	long long int n, x1, x2;
	int pot;
	bool k;
	std::cin >> n;
	while (n != 0) {
		x1 = n*n;
		x2 = 0;
		pot = 1;
		k = false;
		while (!k && x1 != 0) {
			k = x2 != 0 && x1 + x2 == n;
			if (!k) {
				x2 += (x1 % 10) * pot;
				pot *= 10;
				x1 /= 10;
			}
		}
		k = k || x2 != 0 && x1 + x2 == n;
		if (k)std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> n;
	}
return 0;
}