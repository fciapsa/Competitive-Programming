#include <iostream>
#include <string>
#include <cctype>

long int calc(std::string &in, int ini) {
	long int op1, op2;
	if (isdigit(in[ini])) {
		op1 = int(in[ini]) - int('0');
		in.erase(ini, 2);
		return op1;
	}
	else if (in[ini] == '+') {
		if (isdigit(in[ini + 2]) && isdigit(in[ini + 4])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = int(in[ini + 4]) - int('0');
			in.erase(ini, 6);
			return op1 + op2;
		}
		else if (isdigit(in[ini + 2])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = calc(in, ini + 4);
			in.erase(ini, 4);
			return op1 + op2;
		}
		else {
			op1 = calc(in, ini + 2);
			op2 = calc(in, ini + 2);
			in.erase(ini, 2);
			return op1 + op2;
		}
	}
	else if (in[ini] == '-') {
		if (isdigit(in[ini + 2]) && isdigit(in[ini + 4])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = int(in[ini + 4]) - int('0');
			in.erase(ini, 6);
			return op1 - op2;
		}
		else if (isdigit(in[ini + 2])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = calc(in, ini + 4);
			in.erase(ini, 4);
			return op1 - op2;
		}
		else {
			op1 = calc(in, ini + 2);
			op2 = calc(in, ini + 2);
			in.erase(ini, 2);
			return op1 - op2;
		}
	}
	else if (in[ini] == '*') {
		if (isdigit(in[ini + 2]) && isdigit(in[ini + 4])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = int(in[ini + 4]) - int('0');
			in.erase(ini, 6);
			return op1 * op2;
		}
		else if (isdigit(in[ini + 2])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = calc(in, ini + 4);
			in.erase(ini, 4);
			return op1 * op2;
		}
		else {
			op1 = calc(in, ini + 2);
			op2 = calc(in, ini + 2);
			in.erase(ini, 2);
			return op1 * op2;
		}
	}
	else if (in[ini] == '/') {
		if (isdigit(in[ini + 2]) && isdigit(in[ini + 4])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = int(in[ini + 4]) - int('0');
			in.erase(ini, 6);
			return op1 / op2;
		}
		else if (isdigit(in[ini + 2])) {
			op1 = int(in[ini + 2]) - int('0');
			op2 = calc(in, ini + 4);
			in.erase(ini, 4);
			return op1 / op2;
		}
		else {
			op1 = calc(in, ini + 2);
			op2 = calc(in, ini + 2);
			in.erase(ini, 2);
			return op1 / op2;
		}
	}
}

int main() {
	int c, ini;
	std::string in;
	std::cin >> c;
	std::cin.ignore();
	for (int i = 0; i < c; ++i) {
		std::getline(std::cin, in);
		ini = 0;
		std::cout << calc(in, ini) << '\n';
	}
return 0;
}