#include <iostream>

int main() {
	int F;
	std::cin >> F;
	while (F != 0) {
		int i = 0, j;
		bool id = true;

		int x;
		while (i < F && id) {

			j = 0;
			while (j < F && id) {
				std::cin >> x;
				if ((i == j && x != 1) || (i != j && x != 0)) id = false;
				++j;
			}
			if(id)++i;
		}
		while (i < F) {
			while (j < F) {
				std::cin >> x;
				++j;
			}
			j = 0;
			++i;
		}

		if (id) std::cout << "SI\n";
		else std::cout << "NO\n";

		std::cin >> F;
	}
return 0;
}