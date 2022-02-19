#include <iostream>
#include <iomanip>

int main() {
	int L;
	std::cin >> L;
	double N = L;
	double res = (L % 3) / 3;
	std::cout << std::fixed << std::setprecision(12) << (N + res) * (N + res) * (N + res) / 27;
return 0;
}