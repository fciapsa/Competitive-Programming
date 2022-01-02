#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int t, e;
	ll sol, act, ant;
	cin >> t >> e;
	while (t != 0) {
		vector<ll> v(e);
		for (int i = 0; i < e; ++i) cin >> v[i];

		vector<ll> prev(e), post(e);
		for (int i = 1; i < e; ++i) prev[i] = prev[i - 1] + v[i-1];
		post[e - 1] = v[e - 1];
		for (int i = e - 2; i >= 0; --i) post[i] = post[i + 1] + v[i];

		//ini = 0, fin = ini+t-1
		sol = 0;
		for (int i = 1, ind = t; ind < e; ++ind, ++i) sol += i * v[ind];
		ant = sol;
		for (int ini = 1, fin = ini + t - 1; fin < e; ++ini, ++fin) {
			act = ant + prev[ini] - post[fin];
			if (act < sol) sol = act;
			ant = act;
		}

		cout << sol << '\n';

	cin >> t >> e;
	}
}