#include <iostream>
#include <cmath>

int main() {
	int A, B, res1, res2;
	std::cin >> A >> B;

	res1 = A * 100;
	if (res1 % 8 != 0) {
		res1 /= 8;
		++res1;
	}
	else res1 /= 8;
	res2 = B * 10;
	if (res1 == res2) std::cout << res1 << '\n';
	else if (res1 > res2) {
		if (std::floor(res1 / 10) == B) std::cout << res1 << '\n';
		else std::cout << "-1\n";
	}
	else {
		if (std::floor(res2 * 0.08) == A) std::cout << res2 << '\n';
		else std::cout << "-1\n";
	}
	
	return 0;
}