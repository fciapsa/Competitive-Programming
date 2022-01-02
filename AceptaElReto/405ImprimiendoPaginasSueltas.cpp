#include <iostream>

bool resuelveCaso() {
int a, b, ini;
bool sec = false, primero = true;

std::cin >> a;
if (a == 0) return false;

std::cin >> b;
	if (b == 0) std::cout << a << '\n';
	else {
		while (b != 0) {
			if (!sec && b == a + 1) {
				sec = true;
				ini = a;
			}
			else if (sec && b != a + 1) {
				sec = false;
				if (primero) {
					primero = false;
					std::cout << ini << '-' << a;
				}
				else std::cout << ',' << ini << '-' << a;
			}
			else if (primero && b != a + 1) {
				std::cout << a;
				primero = false;
			}
			else if (b != a + 1) std::cout << ',' << a;
			a = b;
			std::cin >> b;
		}
		if (sec && primero) std::cout << ini << '-' << a;
		else if(sec) std::cout << ',' << ini << '-' << a;
		else std::cout << ',' << a;
	std::cout << '\n';
	}

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}