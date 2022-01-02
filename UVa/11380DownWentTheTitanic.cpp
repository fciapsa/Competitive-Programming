#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 2000

#define IN(x) 2*x
#define OUT(x) 2*x+1

bool visited[2000];
int cap[2000][2000];
int parent[2000];
vector<vector<int>> adj;

vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };

int x, y;

bool inside(int i, int j) {
	return i >= 0 && j >= 0 && i < x&& j < y;
}

void bfs(int s, int t) {
	queue<int> q;
	memset(visited, 0, sizeof(visited));
	q.push(s);
	parent[s] = -1; visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!visited[v] && (cap[u][v] > 0)) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad m´as peque˜na en el camino
	int flow = INF, v = t;
	while (v != s) {
		flow = min(cap[parent[v]][v], flow);
		v = parent[v];
	}
	// Mandamos flujo
	v = t;
	while (v != s) {
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; // INVERSA
		v = parent[v];
	}
	return flow;
}

int edmondsKarp(int s, int t) {
	int ret = 0;
	int flow = 0;
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0);
	return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
	int p, pos, x_to, y_to, pos_to, fuente, sumidero;
    cin >> x;
    while (cin) {
        cin >> y >> p;

        vector<string> mat(x);
        for (int i = 0; i < x; ++i) cin >> mat[i];

		pos = 0;
		fuente = 2 * x * y;
		sumidero = fuente + 1;
		adj.assign(2 * x * y + 2, {});
		for (int i = 0; i < adj.size(); ++i) {
			for (int j = 0; j < adj.size(); ++j) cap[i][j] = 0;
		}
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (mat[i][j] == '*') {
					adj[fuente].push_back(IN(pos));
					adj[IN(pos)].push_back(fuente);
					cap[fuente][IN(pos)] = 1;

					adj[IN(pos)].push_back(OUT(pos));
					adj[OUT(pos)].push_back(IN(pos));
					cap[IN(pos)][OUT(pos)] = 1;

					for (int k = 0; k < 4; ++k) {
						x_to = i + vx[k];
						y_to = j + vy[k];
						pos_to = x_to * y + y_to;
						if (inside(x_to, y_to) && mat[x_to][y_to] != '~') {
							adj[OUT(pos)].push_back(IN(pos_to));
							adj[IN(pos_to)].push_back(OUT(pos));
							cap[OUT(pos)][IN(pos_to)] = 1;
						}
					}
				}
				else if (mat[i][j] == '#') {
					adj[OUT(pos)].push_back(sumidero);
					adj[sumidero].push_back(OUT(pos));
					cap[OUT(pos)][sumidero] = p;

					adj[IN(pos)].push_back(OUT(pos));
					adj[OUT(pos)].push_back(IN(pos));
					cap[IN(pos)][OUT(pos)] = INF;

					for (int k = 0; k < 4; ++k) {
						x_to = i + vx[k];
						y_to = j + vy[k];
						pos_to = x_to * y + y_to;
						if (inside(x_to, y_to) && mat[x_to][y_to] != '~') {
							adj[OUT(pos)].push_back(IN(pos_to));
							adj[IN(pos_to)].push_back(OUT(pos));
							cap[OUT(pos)][IN(pos_to)] = INF;
						}
					}
				}
				else if (mat[i][j] == '.') {
					adj[IN(pos)].push_back(OUT(pos));
					adj[OUT(pos)].push_back(IN(pos));
					cap[IN(pos)][OUT(pos)] = 1;

					for (int k = 0; k < 4; ++k) {
						x_to = i + vx[k];
						y_to = j + vy[k];
						pos_to = x_to * y + y_to;
						if (inside(x_to, y_to) && mat[x_to][y_to] != '~') {
							adj[OUT(pos)].push_back(IN(pos_to));
							adj[IN(pos_to)].push_back(OUT(pos));
							cap[OUT(pos)][IN(pos_to)] = 1;
						}
					}
				}
				else if (mat[i][j] == '@') {
					adj[IN(pos)].push_back(OUT(pos));
					adj[OUT(pos)].push_back(IN(pos));
					cap[IN(pos)][OUT(pos)] = INF;

					for (int k = 0; k < 4; ++k) {
						x_to = i + vx[k];
						y_to = j + vy[k];
						pos_to = x_to * y + y_to;
						if (inside(x_to, y_to) && mat[x_to][y_to] != '~') {
							adj[OUT(pos)].push_back(IN(pos_to));
							adj[IN(pos_to)].push_back(OUT(pos));
							cap[OUT(pos)][IN(pos_to)] = INF;
						}
					}
				}

				++pos;
			}
		}

		cout << edmondsKarp(fuente, sumidero) << '\n';

        cin >> x;
    }
    return 0;
}