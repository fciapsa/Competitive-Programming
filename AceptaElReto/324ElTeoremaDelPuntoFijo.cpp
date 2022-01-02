#include <iostream>
#include <vector>

using ll = long long;

ll mcd(ll a, ll b) {
	if (b == 0) return a;
	return mcd(b, a % b);
}

ll mcm(ll a, ll b) {
	return (a * b) / mcd(a, b);
}

int main() {
	std::vector<int> v(101);
	int n, act, cont;
	ll sol;
	std::cin >> n;
	while (n != 0) {
		for (int i = 1; i <= n; ++i) std::cin >> v[i];

		std::vector<bool> marked(n+1, false);
		std::vector<ll> tams;
		for (int i = 1; i <= n; ++i) {
			if (!marked[i]) {
				marked[i] = true;

				act = i;
				cont = 1;
				while (!marked[v[act]]) {
					++cont;
					marked[v[act]] = true;
					act = v[act];
				}

				tams.push_back(cont);
			}
		}

		if (tams.size() == 1) std::cout << tams[0] << '\n';
		else {
			sol = mcm(tams[0], tams[1]);
			for (int i = 2; i < tams.size(); ++i) sol = mcm(sol, tams[i]);
			std::cout << sol << '\n';
		}

	std::cin >> n;
	}
return 0;
}