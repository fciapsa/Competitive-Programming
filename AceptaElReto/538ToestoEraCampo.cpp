#include <iostream>

bool resuelve(){
	int a, b;
	std::cin >> a >> b;

	if(a == 0 && b == 0) return false;

	if (a >= b) std::cout << "CUERDO\n";
	else std::cout << "SENIL\n";

	return true;
}

int main() {
	while (resuelve());
	return 0;
}