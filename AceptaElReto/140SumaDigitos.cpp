#include <iostream>
#include <string>

void resolver(std::string num) {
int suma = 0, digit = 0;
for (int i = 0; i < num.size(); ++i) {
	digit = int(num.at(i)) - int('0');
	suma += digit;
	if (i < num.size() - 1) std::cout << digit << " + ";
	else std::cout << digit << " = " << suma << '\n';
}
}

int main() {
	std::string num = "";
	std::cin >> num;
	while (num.at(0) != '-') {
		resolver(num);
		std::cin >> num;
	}
return 0;
}