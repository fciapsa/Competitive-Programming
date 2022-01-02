#include <iostream>
#include <vector>

const int MOD = 46337;

std::vector<std::vector<int>> nCr(3001, std::vector<int>(3001, -1));
std::vector<int> sol(3001, -1);

int numComb(int n, int r) {
	if (nCr[n][r] != -1) return nCr[n][r];

	if (r == 0) nCr[n][0] = 1;
	else if(n == r) nCr[n][r] = 1;
	else nCr[n][r] = (numComb(n - 1,r) + numComb(n - 1,r - 1)) % MOD;

return nCr[n][r];
}

int solucion(int x) {
	if (sol[x] != -1) return sol[x];

	int aux = 1;
	for (int i = 1,j = x-1; i < x; ++i,--j) {
		aux = (aux + numComb(x, i) * solucion(x - i)) % MOD;
	}

	sol[x] = aux;

return aux;
}

int main() {
	nCr[1][0] = 1;
	nCr[1][1] = 1;
	sol[1] = 1;

	int x;
	std::cin >> x;
	while (std::cin) {
		std::cout << solucion(x) << '\n';

	std::cin >> x;
	}

return 0;
}