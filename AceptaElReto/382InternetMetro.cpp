#include <iostream>

int main() {
	int nc;
	std::cin >> nc;

	int largo, a, pos, r, alcance;
	for (int i = 0; i < nc; ++i) {
		alcance = 0;
		std::cin >> largo >> a;

		for (int k = 0; k < a;++k) {
			std::cin >> pos >> r;
			if (pos - r <= alcance && pos+r > alcance) alcance = pos + r;
		}

		if (alcance < largo) std::cout << "NO\n";
		else std::cout << "SI\n";

	}

return 0;
}