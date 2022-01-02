#include <iostream>
#include <string>

int main() {
	int T, sum, x;
	std::string u;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		sum = 0;
		std::cin >> x;
		while (x != 0) {
			std::cin >> u;
			if (u == "o") sum += x;
			else if (u == "da") sum += 10 * x;
			else if (u == "h") sum += 100 * x;
			else if (u == "k") sum += 1000 * x;
			else if (u == "M") sum += 1000000 * x;
			else sum += 1000000000 * x;

			std::cin >> x;
		}

		if (sum % 1000000000 == 0) std::cout << sum / 1000000000 << " G\n";
		else if (sum % 1000000 == 0) std::cout << sum / 1000000 << " M\n";
		else if (sum % 1000 == 0) std::cout << sum / 1000 << " k\n";
		else if (sum % 100 == 0) std::cout << sum / 100 << " h\n";
		else if (sum % 10 == 0) std::cout << sum / 10 << " da\n";
		else std::cout << sum << " o\n";

	}
return 0;
}