#include <iostream>
#include <string>

int main() {
	int T, sum, ceros, mod;
	std::string num;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> num;
		sum = 0;
		ceros = 0;
		for (int i = 0; i < num.size(); ++i) {
			sum += (int(num[i]) - int('0'));
			if (num[i] == '0') ++ceros;
		}

		mod = sum % 9;
		if (sum == 0 || (mod == 0 && ceros >= 2)) std::cout << "COMPLETO\n";
		else {
			if (ceros == 0) std::cout << "00";
			else if (ceros == 1) std::cout << "0";
			if (mod != 0) std::cout << 9 - mod;
			std::cout << '\n';
		}
	}
	return 0;
}