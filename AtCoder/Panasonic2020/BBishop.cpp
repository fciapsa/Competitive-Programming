#include <iostream>

int main() {
	long long int H, W;
	std::cin >> H >> W;
	long long int sol = H * W;
	if (H == 1 || W == 1) std::cout << "1\n";
	else {
		if (sol % 2 == 0) std::cout << sol / 2 << '\n';
		else std::cout << sol / 2 + 1 << '\n';
	}
return 0;
}