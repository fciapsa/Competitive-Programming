#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define NOTP 101

struct edge {
	ll to, cost;
	bool operator<(edge const& other)const {
		return cost > other.cost;
	}
};

struct nodo {
	ll to, fuel, cost;
	bool operator<(nodo const& other)const {
		return cost > other.cost;
	}
};

unordered_map<int, int> id;
int nextid;
vector<unordered_map<ll,ll>> adyP;
vector<ll> pfprice;
ll tank;

void dijkstra(int s, vector<vector<edge>> const& ady, vector<ll> const& fprice) {
	if (id.count(s) == 0) id[s] = nextid++;
	pfprice[id[s]] = fprice[s];

	vector<ll> distTo(ady.size(), 1e9);
	distTo[s] = 0;
	priority_queue<edge> pq;
	pq.push({ s,0 });

	edge act;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();

		if (act.cost > distTo[act.to]) continue;

		if (act.to != s && fprice[act.to] != NOTP) {
			if (id.count(act.to) == 0) id[act.to] = nextid++;
			adyP[id[s]][id[act.to]] = act.cost;
		}

		for (edge e : ady[act.to]) {
			if (act.cost + e.cost < distTo[e.to]) {
				distTo[e.to] = act.cost + e.cost;
				pq.push({ e.to, distTo[e.to] });
			}
		}
	}
}

ll pdijkstra(int s, int d) {
	unordered_map<ll, unordered_map<ll, ll>> distTo;
	distTo[s][0] = 0;

	nodo act = { s, 0, 0};
	priority_queue<nodo> pq;
	pq.push(act);

	ll purchase, arrival;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();

		if (act.cost > distTo[act.to][act.fuel]) continue;

		if (act.to == d) return act.cost;

		for (auto cv : adyP[act.to]) {
			if (cv.second <= tank) {
				//buying only the strictly necessary
				if (act.fuel >= cv.second) purchase = 0;
				else purchase = cv.second - act.fuel;
				
				arrival = max((ll)0, act.fuel - cv.second);

				if (distTo[cv.first].count(arrival) == 0 ||
					act.cost + pfprice[act.to] * purchase < distTo[cv.first][arrival]) {
					distTo[cv.first][arrival] = act.cost + pfprice[act.to] * purchase;
					pq.push({ cv.first, arrival, distTo[cv.first][arrival] });
				}

				//filling
				purchase = tank - act.fuel;
				arrival = tank - cv.second;
				if (distTo[cv.first].count(arrival) == 0 ||
					act.cost + pfprice[act.to] * purchase < distTo[cv.first][arrival]) {
					distTo[cv.first][arrival] = act.cost + pfprice[act.to] * purchase;
					pq.push({ cv.first, arrival, distTo[cv.first][arrival] });
				}
			}
		}
	}

	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	ll tc, n, m, s, a, b, f, ini, fin, petrols;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> s >> tank;
		vector<vector<edge>> ady(n + 1);
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> f;
			ady[a].push_back({ b,f });
			ady[b].push_back({ a,f });
		}

		vector<ll> fprice(n + 1, NOTP);
		for (int i = 0; i < s; ++i) {
			cin >> a >> b;
			fprice[a] = min(fprice[a], b);
		}

		cin >> ini >> fin;
		fprice[fin] = 0;
		petrols = 0;
		for (int i = 1; i <= n; ++i) if (fprice[i] != NOTP) ++petrols;

		adyP.assign(petrols, {});
		pfprice.assign(petrols, 0);
		id.clear();
		nextid = 0;
		for (int i = 1; i <= n; ++i) {
			if (fprice[i] != NOTP) dijkstra(i, ady, fprice);
		}

		cout << pdijkstra(id[ini], id[fin]) << '\n';
	}
	return 0;
}