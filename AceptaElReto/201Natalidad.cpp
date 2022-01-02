#include <iostream>
#include <string>

const char VACIO = '.';
bool max1, todos2;

bool leeArbol(char raiz) {
	if (max1 || todos2) {
		if (raiz == '.') return false;

		char iz, der;
		std::cin >> iz;
		bool biz = leeArbol(iz);
		std::cin >> der;
		bool bder = leeArbol(der);

		if (biz && bder) max1 = false;
		else if (biz || bder) todos2 = false;
	}
return true;
}

int main() {
	std::string dump;
	char raiz;
	std::cin >> raiz;
	while (raiz != VACIO) {
		max1 = true;
		todos2 = true;
		leeArbol(raiz);
		getline(std::cin,dump);
		if (max1 || todos2) {
			if (max1) std::cout << '1';
			if (todos2) std::cout << '2';
		}
		else std::cout << 'N';
		std::cout << '\n';
	std::cin >> raiz;
	}
return 0;
}