#include <iostream>
#include <algorithm>

struct tInfo {
	int max, act;
};

tInfo leerArbol() {
	int raiz;
	std::cin >> raiz;

	if (raiz == 0) return{ 0,0};
	if (raiz == 1) {
		tInfo hijo = leerArbol();
		return { hijo.max,0};
	}

	tInfo iz = leerArbol();
	tInfo der = leerArbol();
	if (iz.act == der.act) 
		return{ std::max(1 + iz.act,std::max(iz.max,der.max)), 1 + iz.act};
	else return{ std::max(std::max(der.act,std::max(iz.max,iz.act)),der.max),1 + std::min(iz.act,der.act)};
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cout << leerArbol().max << '\n';
	}
return 0;
}