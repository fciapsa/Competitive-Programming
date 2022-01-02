#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
std::vector<ll> primos = { 2,3,5,7,11,13,17,19,23,29};

ll n;
const ll MAX = 1000000001;

ll resolver(ll nDivisores, ll numAct, int primoAct,ll maxPot) {
	if (nDivisores == n) return numAct;

	ll res = MAX;
	for (ll potencia = 1;potencia <= maxPot ; ++potencia) {
		numAct *= primos[primoAct];

		if ((potencia + 1) * nDivisores > n || numAct > res) break;

		res = std::min(res, resolver(nDivisores * (potencia + 1), numAct, primoAct + 1,potencia));
	}

return res;
}

int main() {
	int sol;
	std::cin >> n;
	while (n != 0) {
		sol = resolver(1, 1, 0,29);
		if (sol < MAX) std::cout << sol << '\n';
		else std::cout << "+INF\n";
	std::cin >> n;
	}
return 0;
}