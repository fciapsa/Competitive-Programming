#include <iostream>
#include <string>
#include <stack>

int main() {
	int bajos, altos, tam, sol;
	std::string s;
	std::cin >> s;
	while (std::cin) {
		sol = 0;
		bajos = 0;
		altos = 0;
		std::stack<bool> pila;//false significa bajo, true significa alto
		tam = s.size();
		for (int i = 0; i < tam; ++i) {
			switch (s[i]) {
			case 'H': pila.push(true); 
			break;
			case 'M': if (!pila.empty() && pila.top()) {
				++sol;
				pila.pop();
			}
			else while (!pila.empty()) pila.pop();
			break;
			case 'h':pila.push(false); break;
			case 'm': if (!pila.empty() && !pila.top()) {
				++sol;
				pila.pop();
			}
			else while (!pila.empty()) pila.pop();
			break;
			case '@': while (!pila.empty()) pila.pop();
			break;
			};
		}

		std::cout << sol << '\n';

	std::cin >> s;
	}
return 0;
}