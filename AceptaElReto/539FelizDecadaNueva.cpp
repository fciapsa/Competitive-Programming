#include <iostream>

bool resuelve() {
	int ini, act;
	std::cin >> ini >> act;

	if(!std::cin) return false;

	if ((act - ini) % 10 == 9)std::cout << "FELIZ DECADA NUEVA\n";
	else std::cout << "TOCA ESPERAR\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}