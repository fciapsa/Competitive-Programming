#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype> //isdigit

bool resuelveCaso() {
	std::string expr;
	getline(std::cin, expr);

	if (!std::cin) return false;

	std::stack<int> pila;
	std::queue<int> cola;
	bool validaP = true,validaQ = true;

	int op1, op2;
	for (int i = 0; i < expr.size() && (validaQ || validaP); ++i) {
		if (validaP) {
			if (!isdigit(expr[i])) {
				op2 = pila.top();
				pila.pop();
				op1 = pila.top();
				pila.pop();

				switch (expr[i]) {
				case '+':pila.push(op1 + op2); break;
				case '-':pila.push(op1 - op2); break;
				case '*':pila.push(op1*op2); break;
				case '/':
					if (op2 == 0) validaP = false;
					else pila.push(op1 / op2);
				}
			}
			else pila.push(int(expr[i]) - int('0'));
		}
		if (validaQ) {
			if (!isdigit(expr[i])) {
				op2 = cola.front();
				cola.pop();
				op1 = cola.front();
				cola.pop();

				switch (expr[i]) {
				case '+':cola.push(op1 + op2); break;
				case '-':cola.push(op1 - op2); break;
				case '*':cola.push(op1*op2); break;
				case '/':
					if (op2 == 0) validaQ = false;
					else cola.push(op1 / op2);
				}
			}
			else cola.push(int(expr[i]) - int('0'));
		}
	}

	if (validaP) {
		std::cout << pila.top();
		if (validaQ && pila.top() == cola.front()) std::cout << " = " << cola.front() << '\n';
		else if(validaQ) std::cout << " != " << cola.front() << '\n';
		else std::cout << " != ERROR\n";
	}
	else {
		std::cout << "ERROR";
		if (validaQ) std::cout << " != " << cola.front() << '\n';
		else std::cout << " = ERROR\n";
	}

return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}