#include <iostream>

int main() {
	long int nc, num;
	std::cin >> nc;
	for (long int i = 0; i < nc; ++i) {
		std::cin >> num;
		if (num < 5) std::cout << "0\n";
		else {
			long long int numcincos = 0;
			long long int aux = 5;
			while (aux <= num) {
				numcincos += num / aux;
				aux *= 5;
			}
			std::cout << numcincos << '\n';			
		}
	}
return 0;
}