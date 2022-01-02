#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int k, act, p1, x1, x2;
	bool carry = false, first;
	std::cin >> k;
		if (k <= 12) std::cout << k << '\n';
		else {
			act = 12;
			std::string s = "12";
			while (act < k) {
				p1 = s.size() - 2;

				first = true;
				while (p1 >= 0) {
					if (carry) {
						carry = false;
						while (p1 >= 0 && s[p1] == '9') --p1;
						if (p1 >= 0) {
							s[p1] = char(s[p1] + 1);
							for (int i = p1 + 1; i < s.size(); ++i) s[i] = char(std::max(int('0'), s[p1] - (i - p1)));
						}
						else {
							s = "1" + s;
							for (int i = 1; i < s.size(); ++i) s[i] = '0';
						}

					--p1;
					}
					else {
						if (first) {
							first = false;
							x2 = s[p1+1] - '0' + 1;
						}
						else x2 = s[p1+1] - '0';
						x1 = s[p1] - '0';
						if (x1 == 9 && x2 == 10) carry = true;
						else if (x2 - x1 <= 1) s[p1+1] = char('0' + x2);
						else {
							++x1;
							s[p1] = char('0' + x1);
							for (int i = p1+1; i < s.size(); ++i) s[i] = char(std::max(int('0'), s[p1] - (i - p1)));
						}

						--p1;
					}
				}
				if (carry) {
					carry = false;
					s = "1" + s;
					for (int i = 1; i < s.size(); ++i) s[i] = '0';
				}

			++act;
			}

			std::cout << s << '\n';
		}
return 0;
}