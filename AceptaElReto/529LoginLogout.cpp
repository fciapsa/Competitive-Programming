#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int N, max, act;
	std::cin >> N;
	std::string s;
	for (int i = 0; i < N; ++i) {
		std::cin >> s;
		max = 0;
		act = 0;

		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == 'I') {
				++act;
				if (act > max) max = act;
			}
			else {
				if (act > 0) --act;
				else ++max;
			}
		}

		std::cout << max << '\n';
	}

return 0;
}