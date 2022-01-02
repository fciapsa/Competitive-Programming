#include <bits/stdc++.h>

using namespace std;
#define ll long long

int z, i, m;

int f(int x) {
	return (z * x + i) % m;
}

typedef pair<int, int> uu;
// <µ,λ> : <inicio ciclo, longitud ciclo>
uu floydCycleFinding(int x0) {
	int tortoise = f(x0), hare = f(f(x0));
	while (tortoise != hare) {
		tortoise = f(tortoise); hare = f(f(hare));
	}
	int mu = 0; hare = x0;
	while (tortoise != hare) {
		tortoise = f(tortoise); hare = f(hare); mu++;
	}
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) {
		hare = f(hare); lambda++;
	}
	return uu(mu, lambda);
}

int main() {
    std::ios::sync_with_stdio(false);
    int l, k = 1;
	uu sol;
    cin >> z >> i >> m >> l;
    while (m != 0) {
		sol = floydCycleFinding(l);
		cout << "Case " << k++ << ": " << sol.second << '\n';
        cin >> z >> i >> m >> l;
    }
    return 0;
}