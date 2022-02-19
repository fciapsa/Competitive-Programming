#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1e12

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int r, c;
int in(int x, int y) {
	return x * c + y;
}

int out(int x, int y) {
	return r * c + x * c + y;
}

vector<int> vx = { -1,0,1,0 };
vector<int> vy = { 0,1,0,-1 };

int main() {
	std::ios::sync_with_stdio(false);
	int cr, cc, dx, dy;
	ll sold;
	cin >> r >> c;
	Dinic mf(2*r*c + 1, 2*r*c, 0);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> sold;
			mf.add_edge(in(i, j), out(i, j), sold);
			for (int d = 0; d < 4; ++d) {
				dx = i + vx[d];
				dy = j + vy[d];
				if (dx >= 0 && dx < r && dy >= 0 && dy < c) mf.add_edge(out(i, j), in(dx, dy), INF);
			}

			if (i == 0 || j == 0 || i == r-1 || j == c-1) mf.add_edge(2 * r * c, in(i, j), INF);
		}
	}

	cin >> cr >> cc;
    mf.t = out(cr, cc);
	cout << mf.flow() << '\n';
	return 0;
}