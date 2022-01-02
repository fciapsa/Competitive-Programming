#include <iostream>

int main() {
	int T, s, a, b, aux1, aux2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> s >> a >> b;
		if (s <= a && s <= b) {
			if (a < b) std::cout << b - s << '\n';
			else std::cout << a - s << '\n';
		}
		else if (a <= s && b <= s) {
			if (a < b) std::cout << s - a << '\n';
			else std::cout << s - b << '\n';
		}
		else if (a < s) {
			aux1 = s - a;
			aux2 = b - s;
			if (aux1 < aux2) std::cout << 2 * aux1 + aux2 << '\n';
			else std::cout << 2 * aux2 + aux1 << '\n';
		}
		else {
			aux1 = s - b;
			aux2 = a - s;
			if (aux1 < aux2) std::cout << 2 * aux1 + aux2 << '\n';
			else std::cout << 2 * aux2 + aux1 << '\n';
		}
	}
return 0;
}