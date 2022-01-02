#include <iostream>

int main() {
	int n; char c;
	std::cin >> n >> c;
	int tam, act, space;
	while (!(n == 0 && c == '0')) {
		if (n == 0) std::cout << '\n';
		else {
			tam = 3 * n - 2;
			act = n;
			for (int i = 0; i < n; ++i) {
				space = (tam - act) / 2;
				for (int j = 0; j < space; ++j) std::cout << ' ';
				for (int j = 0; j < act; ++j) std::cout << c;
				for (int j = 0; j < space; ++j) std::cout << ' ';
				std::cout << '\n';

				act += 2;
			}
			act -= 4;
			for (int i = 1; i < n; ++i) {
				space = (tam - act) / 2;
				for (int j = 0; j < space; ++j) std::cout << ' ';
				for (int j = 0; j < act; ++j) std::cout << c;
				for (int j = 0; j < space; ++j) std::cout << ' ';
				std::cout << '\n';

				act -= 2;
			}
		}


	std::cin >> n >> c;
	}
return 0;
}
