#include <bits/stdc++.h>

using namespace std;
#define ll long long

int mx, l, w;

struct arbol {
	int x, y;
	bool operator<(arbol const& other)const {
		return x < other.x;
	}
};

void leftBorder(int act, vector<arbol> const& v, int inf, int sup) {
	if (act == v.size()) mx = max(mx, (sup - inf) * l);
	else if (inf < v[act].y && v[act].y < sup) {
		mx = max(mx, (sup - inf) * v[act].x);
		leftBorder(act + 1, v, v[act].y, sup);
		leftBorder(act + 1, v, inf, v[act].y);
	}
	else leftBorder(act + 1, v, inf, sup);
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, k, x, y, dx, dy, sup, inf;
	cin >> tc;
	while (tc--) {
		cin >> l >> w;
		cin >> k;
		vector<arbol> v;
		while (k != 0) {
			if (k == 1) {
				cin >> x >> y;
				v.push_back({ x,y });
			}
			else {
				cin >> x >> y >> dx >> dy;
				for (int i = x, j = y, it = 0; it < k; i += dx, j += dy, ++it) v.push_back({ i,j });
			}
			cin >> k;
		}

		sort(v.begin(), v.end());

		mx = 0;
		for (int i = 0; i < v.size(); ++i) {//probar con cada arbol como limite izquierdo
			sup = w; inf = 0;//limite superior e inferior del rectangulo
			for (int j = i + 1; j < v.size(); ++j) {
				if (v[j].x > v[i].x) {
					mx = max(mx, (sup - inf) * (v[j].x - v[i].x));
					if (v[j].y <= v[i].y) inf = max(inf, v[j].y);
					if (v[j].y >= v[i].y) sup = min(sup, v[j].y);
				}
			}
			mx = max(mx, (sup - inf) * (l - v[i].x));
		}
		//probar con todos los rectangulos que tienen el margen izquierdo como limite izquierdo
		leftBorder(0, v, 0, w);

		cout << mx << '\n';
	}
	return 0;
}