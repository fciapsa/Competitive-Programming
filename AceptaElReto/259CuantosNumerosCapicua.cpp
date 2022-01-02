#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;
	while (N != 0) {
		if (N > 2) {
			std::cout << '9';
			std::string s = "";
			N = N-1;
			N = N/2;
			while (N > 0) {
				s += "0";
				--N;
			}
			std::cout << s << '\n';
		}
		else if (N == 1) std::cout << "10\n";
		else std::cout << "9\n";

	std::cin >> N;
	}
return 0;
}