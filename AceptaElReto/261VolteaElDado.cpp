#include <iostream>
#include <vector>

const int MAX = 1000, SUM = 7;
std::vector<std::vector<int>> memo(MAX + 1, std::vector<int>(SUM, -1));

int yo(int acum, int d) {
	int falta = MAX - acum;
	//casos base o ya calculados
	if (memo[falta][d] != -1) return memo[falta][d];

	//casos recursivos no calculados
	int gano = 0;
	for (int i = 1; i < SUM && gano == 0; ++i) {
		if (i != d && i != SUM - d) {
			gano = 1 - yo(acum + i, i);//el inverso, pues paso turno
		}
	}
	memo[falta][d] = gano;
return gano;
}

void rellenarCasosBase(){
	for (int i = 1; i < SUM; ++i) memo[0][i] = 1;
	for (int i = 1; i < SUM; ++i) memo[1][i] = 0;
	for (int i = 1; i < SUM; ++i) {
		if (i != 1 && i != 6) memo[2][i] = 1;
		else memo[2][i] = 0;
	}
	for (int i = 1; i < SUM; ++i) {
		if ((i != 2 && i != 5) || (i != 1 && i != 6)) memo[3][i] = 1;
		else memo[3][i] = 0;
	}
	for (int i = 1; i < SUM; ++i) {
		if (i != 4 && i != 3) {
			memo[4][i] = 1;
			memo[5][i] = 1;
		}
		else {
			memo[4][i] = 0;
			memo[5][i] = 0;
		}
	}
	for (int i = 1; i < SUM; ++i) {
		if (i != 2 && i != 5) memo[6][i] = 1;
		else memo[6][i] = 0;
	}

}

int main() {
	rellenarCasosBase();
	int N, acum, d;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> acum >> d;
		if (yo(acum, d) == 1) std::cout << "GANA\n";
		else std::cout << "PIERDE\n";
	}
return 0;
}