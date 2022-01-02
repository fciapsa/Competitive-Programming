#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF

struct edge {
	int to, d;
	bool operator<(edge const& other)const {
		return d > other.d;
	}
};

vector<vector<edge>> adyList;
vector<int> distTo;
int n;

void dijkstra(int s) {
	distTo.assign(n, 1e9);
	distTo[s] = 0;
	priority_queue<edge> pq;
	pq.push({ s, 0 });
	edge act;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();

		if (act.d > distTo[act.to]) continue;

		for (edge e : adyList[act.to]) {
			if (distTo[e.to] > distTo[act.to] + e.d) {
				distTo[e.to] = distTo[act.to] + e.d;
				pq.push({ e.to, distTo[e.to] });
			}
		}
	}
}

int V; // vértices del grafo completo
vector<vector<int>> dist; // matriz de adyacencia del grafo
vector<vector<int>> memo; // tabla de DP
// devuelve el coste de ir desde pos al origen (el vértice 0)
// pasando por todos los vértices no visitados (con un bit a 0)
int tsp(int pos, int visitados) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
		return dist[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];
	int res = 1000000000; // INF
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado vértice i
			res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i)));
	return memo[pos][visitados] = res;
}

int main() {
    std::ios::sync_with_stdio(false);

	int tc, m, x, y, d;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		adyList.assign(n, {});
		while (m--) {
			cin >> x >> y >> d;
			adyList[x].push_back({ y,d });
			adyList[y].push_back({ x,d });
		}

		cin >> V;
		++V;

		dist.assign(V, vector<int>(V, 0));
		// rellenamos la matriz de distancias entre vértices
		vector<int> sources(V);//sources[0] = 0
		for (int i = 1; i < V; ++i) cin >> sources[i];
		for (int i = 0; i < V; ++i) {
			dijkstra(sources[i]);
			for (int j = 0; j < V; ++j) {
				dist[i][j] = distTo[sources[j]];
			}
		}
		memo.assign(V, vector<int>(1 << V, -1));
		cout << tsp(0, 1) << '\n';

	}

    return 0;
}