#include <bits/stdc++.h>

using namespace std;
#define ll long long

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
	int a, b, mx, rej;
	cin >> a;
	while (cin) {
		if (a == -1) cout << "0\n";
		else {
			cin >> b;
			vector<pair<int, int>> edges;
			edges.push_back({ a,b });
			mx = max(a, b);
			cin >> a;
			while (a != -1) {
				mx = max(mx, a);
				cin >> b;
				mx = max(mx, b);
				edges.push_back({ a,b });
				cin >> a;
			}
			UFDS uf(mx + 1);
			rej = 0;
			for (int i = 0; i < edges.size(); ++i) {
				if (uf.find(edges[i].first) != uf.find(edges[i].second)) {
					uf.merge(edges[i].first, edges[i].second);
				}
				else ++rej;
			}
			cout << rej << '\n';
		}

		cin >> a;
	}
    return 0;
}