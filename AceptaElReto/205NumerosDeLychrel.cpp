#include <iostream>
#include <string>

const int MAX = 1000000000;

bool capicua(long long int n) {
	std::string num = std::to_string(n);
	bool ok = true;
	for (int i = 0; i < num.size() / 2 && ok; ++i) {
		ok = num[i] == num[num.size() - 1 - i];
	}

return ok;
}

int main() {
	long long int T, n, aux, rev, pot, iter;
	bool found;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		iter = 0;
		found = false;
		while (!found && n <= MAX) {
			++iter;
			aux = n / 10;
			pot = 1;
			while (aux > 0) {
				pot *= 10;
				aux /= 10;
			}

			aux = n;
			rev = 0;
			while (aux > 0) {
				rev += (aux % 10) * pot;
				aux /= 10;
				pot /= 10;
			}

			n += rev;
			found = capicua(n);
		}

		if (found) std::cout << iter << ' ' << n << '\n';
		else std::cout << "Lychrel?\n";
	}
return 0;
}