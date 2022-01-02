#include <iostream>
#include <string>

int main() {
	std::string num;
	bool b1, b2;
	int last;

	std::cin >> num;
	while (num != "0") {
		if (num.size() == 1)std::cout << "NO\n";
		else if (num.size() == 2) std::cout << "SI\n";
		else {
			last = num.size() - 1;
			b1 = false; b2 = false;
			for (int k = 1; k <= last && !(b1 && b2); ++k) {
				b1 = false; b2 = false;

				if (k == 1) b1 = true;
				else {
					b1 = true;
					for (int i = 0, j = k - 1; i < j && b1; ++i, --j) {
						b1 = num[i] == num[j];
					}
				}

				if (b1) {
					if (k == last) b2 = true;
					else if(num[k] != '0') {
						b2 = true;
						for (int i = k, j = last; i < j && b2; ++i, --j) {
							b2 = num[i] == num[j];
						}
					}
				}
			}

			if (b1 && b2) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> num;
	}
return 0;
}