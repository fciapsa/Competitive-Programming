#include <iostream>

int main() {
	int T;
	char a, b, aux;
	int x, y;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> a >> aux >> x >> b >> aux >> y;
		if ((a == 'V' && b == 'T') || (a == 'T' && b == 'V')) std::cout << "D=" << x * y << '\n';
		else if (a == 'D' && b == 'V') std::cout << "T=" << x / y << '\n';
		else if (a == 'V' && b == 'D') std::cout << "T=" << y / x << '\n';
		else if (a == 'T' && b == 'D') std::cout << "V=" << y / x << '\n';
		else std::cout << "V=" << x / y << '\n';
	}
return 0;
}