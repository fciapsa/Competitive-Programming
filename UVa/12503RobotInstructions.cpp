#include <iostream>
#include <vector>
#include <string>

int main() {
	int t, n, p, x;
	std::string s;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		p = 0;
		std::vector<int> v(n+1);
		for (int i = 1; i <= n; ++i) {
			std::cin >> s;
			if (s == "LEFT") v[i] = -1;
			else if (s == "RIGHT") v[i] = 1;
			else {
				std::cin >> s >> x;
				v[i] = v[x];
			}

			p += v[i];
		}
		std::cout << p << '\n';
	}
return 0;
}