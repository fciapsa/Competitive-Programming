#include <iostream>
#include <vector>

const int MOD = 1000000007, TAM = 1001;
std::vector<std::vector<int>> comb(TAM, std::vector<int>(TAM, -1));

int nCr(int n, int k) {
	if (comb[n][k] != -1) return comb[n][k];

	if (k == 0 || n == k) {
		comb[n][k] = 1;
		return 1;
	}
	if (k == 1 || k == n-1) {
		comb[n][k] = n;
		return n;
	}

	int aux = (nCr(n - 1, k) + nCr(n - 1, k - 1)) % MOD;
	comb[n][k] = aux;
return aux;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	while (n != 0 || k != 0) {
		if (n == 0 || k > n) std::cout << "0\n";
		else std::cout << nCr(n, k) << '\n';
	std::cin >> n >> k;
	}
return 0;
}