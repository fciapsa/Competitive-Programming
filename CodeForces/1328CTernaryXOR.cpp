#include <iostream>
#include <string>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	int t, n;
	bool first;
	std::string s;
	std::cin >> t;
	for (int m = 0; m < t; ++m) {
		std::cin >> n >> s;
		std::vector<char> a, b;
		a.push_back('1');
		b.push_back('1');
		first = true;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '0') {
				a.push_back('0');
				b.push_back('0');
			}
			else if (s[i] == '1') {
				if (first) {
					first = false;
					a.push_back('1');
					b.push_back('0');
				}
				else {
					a.push_back('0');
					b.push_back('1');
				}
			}
			else {
				if (first) {
					a.push_back('1');
					b.push_back('1');
				}
				else {
					a.push_back('0');
					b.push_back('2');
				}
			}
		}
		for (int i = 0; i < n; ++i) std::cout << a[i];
		std::cout << '\n';
		for (int i = 0; i < n; ++i) std::cout << b[i];
		std::cout << '\n';
	}
return 0;
}