#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string num;
	int T, dif, x, pos;
	bool stop;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> num;
		std::vector<bool> marcas(num.size(), false);
		marcas[0] = true;
		pos = 0;
		stop = false;
		dif = 1;

		for (int i = 0; i < num.size() && !stop; ++i) {
			x = num[pos] - int('0');
			pos = (pos + x) % num.size();
			if (marcas[pos]) stop = true;
			else {
				++dif;
				marcas[pos] = true;
			}
		}

		if (dif == num.size() && pos == 0) std::cout << "SALTARINES\n";
		else std::cout << "NORMALES\n";
	}
	return 0;
}
