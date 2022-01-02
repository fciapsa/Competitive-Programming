#include <iostream>
#include <string>

const int LAST_DIGIT = 9;

int main() {
	std::string a, b;
	bool carry;
	int sol, i, j, zero = int('0');
	std::cin >> a >> b;
	while (a != "0"|| b != "0") {
		sol = 0;
		carry = false;

		i = a.size() - 1;
		j = b.size() - 1;
		while ((i >= 0 && j >= 0) || (carry && (j >= 0 || i >= 0))) {
			if(i >= 0 && j >= 0){
				if (int(a[i]) - zero + int(b[j]) - zero + int(carry) > LAST_DIGIT) {
					++sol;
					carry = true;
				}
				else carry = false;
			}
			else if (i >= 0) {
				if (int(a[i]) - zero + 1 > LAST_DIGIT) ++sol;
				else carry = false;
			}
			else {
				if (int(b[j]) - zero + 1 > LAST_DIGIT) ++sol;
				else carry = false;
			}

			--i;
			--j;
		}
		std::cout << sol << '\n';

		std::cin >> a >> b;
	}
return 0;
}