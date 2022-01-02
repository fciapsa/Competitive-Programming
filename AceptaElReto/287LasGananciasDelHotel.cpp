#include <iostream>

#define ll long long
const ll MOD = 78787, INV = 52525;
/*Como queremos operar en aritmetica modular con MOD=78787 que es un primo, todo elemento tiene inverso multiplicativo
El que nos interesa para este problema, el del 3, es 52525 ya que [3x52525]mod = [1]mod
*/

int main() {
	ll n, cost, x, sol, hasta, from;
	std::cin >> cost;
	while (std::cin) {
		std::cin >> n;
		sol = 0;
		if (n % 2 == 0) hasta = n / 2 - 1;
		else hasta = n / 2;

		for (int i = 0; i < hasta; ++i) {
			std::cin >> x;
			sol += cost * x;
			sol %= MOD;
			cost *= 3;
			cost %= MOD;
		}

		std::cin >> x;
		sol += cost * x;
		sol %= MOD;
		if (n % 2 == 0) {
			std::cin >> x;
			sol += cost * x;
			sol %= MOD;
			from = hasta + 2;
		}
		else from = hasta + 1;

		for (int i = from; i < n; ++i) {
			cost *= INV;
			cost %= MOD;
			std::cin >> x;
			sol += cost * x;
			sol %= MOD;
		}
		std::cout << sol << '\n';
	std::cin >> cost;
	}
return 0;
}