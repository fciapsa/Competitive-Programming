#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct arista {
    int u, v, c;
    bool operator<(arista const& other) const {
        return c > other.c;
    }
};

struct UFDS {
	vector<int> p;
	int numSets;
	UFDS(int n) : p(n, 0), numSets(n) {
		for (int i = 0; i < n; ++i) p[i] = i;
	}
	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		int i = find(x), j = find(y);
		if (i == j) return;
		p[i] = j;
		--numSets;
	}
};

int main() {
    std::ios::sync_with_stdio(false);
	int tc, n, m, u, v, c, k = 1, sol;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
		vector<arista> v(m);
		while (m--) cin >> v[m].u >> v[m].v >> v[m].c;
		sort(v.begin(), v.end());

		UFDS uf(n);
		for (int i = 0; i < v.size(); ++i) {
			if (uf.find(v[i].u) != uf.find(v[i].v)) {
				uf.merge(v[i].u, v[i].v);
				sol = v[i].c;
			}
			if (uf.numSets == 1) break;
		}

		cout << "Case #" << k++ << ": " << sol << '\n';
    }
    return 0;
}