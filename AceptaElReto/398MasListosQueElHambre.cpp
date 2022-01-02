#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

struct tPar {
	int x, y;
};
int LEJOS, LEJOS_SIG;

int DP(tPar const& dest, std::vector<tPar> const& botones, 
	std::vector<std::vector<std::vector<std::vector<int>>>>& memoria, int botR1, int botR2, int acumR1, int acumR2) {

	int next = std::max(botR1, botR2) + 1;

	if (next == memoria.size()) { //solo queda salir
		int distSalida1 = std::abs(botones[botR1].x - dest.x) + std::abs(botones[botR1].y - dest.y) - acumR1;
		if (distSalida1 < 0) distSalida1 = 0;
	    int distSalida2 = std::abs(botones[botR2].x - dest.x) + std::abs(botones[botR2].y - dest.y) - acumR2;
		if (distSalida2 < 0) distSalida2 = 0;

		return std::max(distSalida1 + 1, distSalida2 + 1);
	}

	if (acumR2 > 0) {
		if (memoria[botR1][botR2][1][acumR2] != -1) return memoria[botR1][botR2][1][acumR2];
	}
	else if(memoria[botR1][botR2][0][acumR1] != -1) return memoria[botR1][botR2][0][acumR1];
	
	
	int distR1 = std::abs(botones[botR1].x - botones[next].x) +
		std::abs(botones[botR1].y - botones[next].y) - acumR1;
	int sobraR1 = 0;
	if (distR1 < 0) {
		sobraR1 = -distR1;
		distR1 = 0;
	}

	int distR2 = std::abs(botones[botR2].x - botones[next].x) +
		std::abs(botones[botR2].y - botones[next].y) - acumR2;
	int sobraR2 = 0;
	if (distR2 < 0) {
		sobraR2 = -distR2;
		distR2 = 0;
	}

	int vaR1 = distR1 + DP(dest, botones, memoria, next, botR2, 0, std::min(acumR2 + distR1,LEJOS));	
	int vaR2 = distR2 + DP(dest, botones, memoria, botR1, next, std::min(acumR1 + distR2,LEJOS), 0);

	int min = std::min(vaR1, vaR2);
	if (acumR2 > 0) {
		memoria[botR1][botR2][1][acumR2] = min;
		if (min == vaR2 && sobraR2 > 0) {
			int aux = sobraR2, i = 1;
			while (aux > 0) {
				memoria[botR1][botR2][1][acumR2 - i] = min;
				--aux;
				++i;
			}
			for (int j = acumR2 + 1; j < LEJOS_SIG; ++j) {
				memoria[botR1][botR2][1][j] = min;
			}
		}
	}
	else {
		memoria[botR1][botR2][0][acumR1] = min;
		if (min == vaR1 && sobraR1 > 0) {
			int aux = sobraR1, i = 1;
			while (aux > 0) {
				memoria[botR1][botR2][0][acumR1 - i] = min;
				--aux;
				++i;
			}
			for (int j = acumR1 + 1; j < LEJOS_SIG; ++j) {
				memoria[botR1][botR2][0][j] = min;
			}
		}
	}

return min;
}

bool resuelve() {
	int F, C;
	std::cin >> F >> C;

	if (!std::cin) return false;

	tPar dest = {F,C};
	int N;
	std::cin >> N;
	std::vector<tPar> botones(N + 1);
	botones[0] = { 1,1 };
	for (int i = 1; i <= N; ++i) {
		std::cin >> botones[i].x >> botones[i].y;
	}
	LEJOS = F + C - 2;
	LEJOS_SIG = LEJOS + 1;

	std::vector<std::vector<std::vector<std::vector<int>>>> memoria(N + 1,
		std::vector<std::vector<std::vector<int>>>(N + 1, std::vector<std::vector<int>>(2, std::vector<int>(LEJOS_SIG, -1))));

	std::cout << DP(dest, botones, memoria, 0, 0, 0, 0) << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}