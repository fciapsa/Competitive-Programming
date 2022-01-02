#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int toNum(std::string const&dig) {
	int n = 0, pot = 1;
	for (int i = dig.size() - 1; i >= 0; --i) {
		n += (int(dig[i]) - int('0')) * pot;
		pot *= 10;
	}
return n;
}

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		std::string N;
		std::cin >> N;

		if (N == "6174") std::cout << "0\n";
		else if(N == "0") std::cout << "8\n";
		else if (N.size() == 4 && N[0] == N[1] && N[1] == N[2] && N[2] == N[3]) std::cout << "8\n";
		else {
			while (N.size() < 4) {
				N.push_back('0');
			}

			int aux = 0;
			std::sort(N.begin(), N.end(), std::greater<char>());
			aux += toNum(N);
			std::sort(N.begin(), N.end(), std::less<char>());
			aux -= toNum(N);

			int iter = 1;
			while (aux != 6174) {
				++iter;
				N = std::to_string(aux);
				while (N.size() < 4) {
					N.push_back('0');
				}

				aux = 0;
				std::sort(N.begin(), N.end(), std::greater<char>());
				aux += toNum(N);
				std::sort(N.begin(), N.end(), std::less<char>());
				aux -= toNum(N);
			}
			std::cout << iter << '\n';
		}	
	}
return 0;
}