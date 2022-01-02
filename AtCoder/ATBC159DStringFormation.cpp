#include <iostream>
#include <deque>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::string s;
	bool reverse = false;
	std::cin >> s;
	std::deque<char> ini, fin;

	int Q;
	std::cin >> Q;
	int T, F;
	char c;
	for (int i = 0; i < Q; ++i) {
		std::cin >> T;
		if (T == 1) reverse = !reverse;
		else {
			std::cin >> F >> c;
			if (F == 1) {
				if (!reverse) ini.push_back(c);
				else fin.push_back(c);
			}
			else {
				if (!reverse) fin.push_back(c);
				else ini.push_back(c);
			}
		}
	}

	if (reverse) {
		while (!fin.empty()) {
			std::cout << fin.back();
			fin.pop_back();
		}
		for (int i = s.size() - 1; i >= 0; --i) std::cout << s[i];
		while (!ini.empty()) {
			std::cout << ini.front();
			ini.pop_front();
		}
		std::cout << '\n';
	}
	else {
		while (!ini.empty()) {
			std::cout << ini.back();
			ini.pop_back();
		}
		std::cout << s;
		while (!fin.empty()) {
			std::cout << fin.front();
			fin.pop_front();
		}
		std::cout << '\n';
	}
return 0;
}