#include <iostream>

bool movil(int &p, int PI,int DI, int PD, int DD) {
	if (PI != 0 && PD != 0) {
		p = PI + PD;
		return PI * DI == PD * DD;
	}
	else if (PI == 0 && PD == 0) {
		int pi, di, pd, dd;
		std::cin >> pi >> di >> pd >> dd;
		bool aux1 = movil(p, pi, di, pd, dd);
		PI = p;
		std::cin >> pi >> di >> pd >> dd;
		bool aux2 = movil(p, pi, di, pd, dd);
		PD = p;
		p = PI + PD;
		return aux1 && aux2 && PI*DI == PD * DD;
	}
	else if (PI == 0) {
		int pi, di, pd, dd;
		std::cin >> pi >> di >> pd >> dd;
		bool aux = movil(p, pi, di, pd, dd);
		PI = p;
		p += PD;
		return aux && PI*DI == PD * DD;
	}
	else {
		int pi, di, pd, dd;
		std::cin >> pi >> di >> pd >> dd;
		bool aux = movil(p, pi, di, pd, dd);
		PD = p;
		p += PI;
		return aux && PI*DI == PD *DD;
	}
}

bool resuelveCaso() {
	int p = 0;
	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;

	if (pi == 0 && di == 0 && pd == 0 && dd == 0) return false;

	bool sol = movil(p,pi,di,pd,dd);
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";
return true;
}

int main(){
	while(resuelveCaso());
return 0;
}