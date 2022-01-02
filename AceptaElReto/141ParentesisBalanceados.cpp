#include <iostream>
#include <string>
#include <stack>

bool equilibrada(std::string const& s) {
	std::stack<char> pila;
	bool equi = true;
	for (int i = 0; i < s.size() && equi; ++i) {
		switch (s[i]) {
		case '(': pila.push('('); break;
		case ')': if (!pila.empty()) {
			equi = pila.top() == '(';
			pila.pop();
		}
				  else equi = false; break;
		case '[': pila.push('['); break;
		case ']': if (!pila.empty()) {
			equi = pila.top() == '[';
			pila.pop();
		}
				  else equi = false; break;
		case '{': pila.push('{'); break;
		case '}': if (!pila.empty()) {
			equi = pila.top() == '{';
			pila.pop();
		}
				  else equi = false; break;
		}
	}
	//Mirar si habia el mismo numero de cerrados que de abiertos
	equi = equi && pila.empty();

	return equi;
}

bool resuelve() {
	std::string s = "";
	getline(std::cin, s);

	if (!std::cin) return false;

	if (equilibrada(s)) std::cout << "YES\n";
	else std::cout << "NO\n";


	return true;
}

int main() {
	while (resuelve());
	return 0;
}