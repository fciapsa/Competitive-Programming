#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>

struct tCoord {
	int x, y;
};

int DP(int puestoMica,int puestoDina, std::vector<tCoord> const&puntos,
	std::vector<std::vector<int>> & memoria, std::vector<std::vector<bool>> & marcas) {

	int sig = std::max(puestoMica, puestoDina) + 1;
	if (sig == memoria.size()) return 0;//ya he visitado todos los puntos

	if (marcas[puestoMica][puestoDina]) return memoria[puestoMica][puestoDina];

	marcas[puestoMica][puestoDina] = true;//aviso de que ya se ha lanzado este calculo
	int distMica = std::abs(puntos[sig].x - puntos[puestoMica].x) + std::abs(puntos[sig].y - puntos[puestoMica].y);
	int distDina = std::abs(puntos[sig].x - puntos[puestoDina].x) + std::abs(puntos[sig].y - puntos[puestoDina].y);
	memoria[puestoMica][puestoDina] = std::min(distMica + DP(sig, puestoDina, puntos, memoria, marcas),
		distDina + DP(puestoMica, sig, puntos, memoria, marcas));
return memoria[puestoMica][puestoDina];
}

int main() {
	int nc;
	std::cin >> nc;

	int N;
	const tCoord posMica = { 0,0 }, posDina = { 0,0 };
	for (int i = 0; i < nc; ++i) {
		std::cin >> N;
		std::vector<tCoord> puntos(N+1);
		puntos[0] = { 0,0 };
		for (int j = 1; j <= N; ++j) {
			std::cin >> puntos[j].x >> puntos[j].y;
		}

		std::vector<std::vector<int>> memoria(N+1,std::vector<int>(N+1));
		std::vector<std::vector<bool>> marcas(N+1, std::vector<bool>(N+1, false));
		std::cout << DP(0, 0,puntos, memoria,marcas) << '\n';
		
	}
return 0;
}