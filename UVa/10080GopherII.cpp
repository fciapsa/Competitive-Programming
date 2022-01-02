#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define EPS 1e-8

struct punto {
	double x, y;
	double dist2(punto const& other) const {
		return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
	}
};

int n, m;//n parte izquierda, m parte derecha
vector<vector<int>> grafo; // dirigido, tamaño n
vector<int> match, vis;
int aug(int l) {//devuelve 1 si encuentra augmenting path
				//en el matching representado en match
	if (vis[l]) return 0;
	vis[l] = 1;
	for (auto r : grafo[l]) {
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}
//en main
int berge_mcbm() {
	int mcbm = 0;
	match.assign(m, -1);
	for (int l = 0; l < n; ++l) {
		vis.assign(n, 0);
		mcbm += aug(l);
	}
	return mcbm;
}

int main() {
	std::ios::sync_with_stdio(false);
	int s, v;
	double maxDist2;
	punto hole;
	cin >> n;
	while (cin) {
		cin >> m >> s >> v;
		maxDist2 = s * v * s * v;

		vector<punto> gophers(n);
		for (int i = 0; i < n; ++i) cin >> gophers[i].x >> gophers[i].y;

		grafo.assign(n, {});
		for (int i = 0; i < m; ++i) {
			cin >> hole.x >> hole.y;
			for (int j = 0; j < n; ++j) {
				if (fabs(gophers[j].dist2(hole)) < maxDist2 + EPS) grafo[j].push_back(i);
			}
		}

		cout << n - berge_mcbm() << '\n';

		cin >> n;
	}

	return 0;
}