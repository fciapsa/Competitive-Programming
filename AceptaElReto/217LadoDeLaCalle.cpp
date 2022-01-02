#include <iostream>

int main() {
	int num = 0;
	std::cin >> num;
	while (num != 0) {
		if (num%2 == 0) {
			std::cout << "DERECHA\n";
	}
		else std::cout << "IZQUIERDA\n";
		std::cin >> num;
	}
system("PAUSE");
return 0;
}