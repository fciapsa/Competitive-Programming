#include <iostream>
#include <vector>

const int MOD = 1000000007;
std::vector<int> memoria(10001, -1);

int DP(int n) {
	if (memoria[n] != -1) return memoria[n];

	int hasta, res = 0;
	if (n < 10) hasta = n;
	else hasta = 10;
	for (int i = hasta; i > 0; --i) {
		if (n - i == 0) res += 1;
		else {
			if (memoria[n - i - 1] != -1) res += memoria[n - i - 1];
			else res += DP(n - i - 1);
		}
		res %= MOD;
	}
	memoria[n] = res;
return res;
}

int main() {
	memoria[0] = 0;//llegamos dejando el pulso de espera, luego no es un numero marcado valido
	//el caso base de numero valida, contando el pulso de espera, seria -1 pero no puedo poner tal indice
	int T, n;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> n;
		std::cout << DP(n) << '\n';
	}
return 0;
}