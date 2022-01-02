#include <iostream>
#include <string>
#include <stack>

int main() {
	std::string s;
	int act, sol;
	char enMedio;
	getline(std::cin, s);
	while (std::cin) {
		if (s.size() < 3) std::cout << "0\n";
		else {
			sol = 0;
			std::stack<char> anteriores;
			anteriores.push(s[0]);
			anteriores.push(s[1]);
			act = 2;
			while (act < s.size()) {
				enMedio = anteriores.top();
				anteriores.pop();
				if (enMedio == 'A' && anteriores.top() == 'R' && s[act] == 'V') {
					++sol;
					anteriores.pop();
					if (anteriores.empty()) {
						if (act + 2 < s.size()) {
							anteriores.push(s[act + 1]);
							anteriores.push(s[act + 2]);
						}
						act += 3;
					}
					else if (anteriores.size() == 1) {
						if (act + 1 < s.size()) anteriores.push(s[act + 1]);
						act += 2;
					}
					else ++act;
				}
				else {
					anteriores.push(enMedio);
					anteriores.push(s[act]);
					++act;
				}
			}

			std::cout << sol << '\n';
		}

	getline(std::cin, s);
	}
return 0;
}