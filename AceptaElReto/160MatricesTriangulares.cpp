#include <iostream>

int main() {
	int n;
	std::cin >> n;

	bool triang1, triang2;
	int aux;
	while (n != 0) {
		triang1 = true; triang2 = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cin >> aux;
				if (triang1 && j < i && aux != 0) triang1 = false;
				if (triang2 && j > i && aux != 0) triang2 = false;
			}
		}

		if (triang1 || triang2) std::cout << "SI\n";
		else std::cout << "NO\n";
		
	std::cin >> n;
	}
return 0;
}