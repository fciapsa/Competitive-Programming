#include <iostream>

int raizDiv(int n) {
	int r = 1;
	while (n >= (r + 1)*(r + 1)) {
		++r;
	}
	while (n%r != 0) --r;
return n / r;
}

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::cout << raizDiv(n) << '\n';
		std::cin >> n;
	}
return 0;
}