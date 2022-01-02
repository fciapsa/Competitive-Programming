#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

struct tInfo {
	int h, max, min;
	bool b;
};

tInfo esAVL() {
	int raiz;
	std::cin >> raiz;

	if (raiz == -1) return{ 0,-1,INT_MAX,true };

	tInfo iz = esAVL();
	tInfo der = esAVL();
	return{ 1 + std::max(iz.h,der.h), std::max(raiz,der.max), std::min(raiz,iz.min),
		iz.b && der.b && std::abs(iz.h - der.h) <= 1 && raiz > iz.max && raiz < der.min};
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		if (esAVL().b) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}