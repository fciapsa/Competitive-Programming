#include <iostream>

int main() {
	int N, a, b, r;
	std::cin >> N;
	while (N--) {
		std::cin >> a >> b >> r;
		a *= b;
		if (r <= a) std::cout << "1\n";
		else if (r % a == 0) std::cout << r / a << '\n';
		else std::cout << r / a + 1 << '\n';
	}
return 0;
}