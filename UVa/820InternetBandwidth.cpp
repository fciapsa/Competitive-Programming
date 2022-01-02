#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<unordered_set<int>> adj;
vector<vector<int>> cap;
vector<int> visited, parent;

void bfs(int s, int t) {
    queue<int> q;
    visited.assign(n + 1, 0);
    q.push(s);
    parent[s] = -1; visited[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int v: adj[u]) {
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
    int flow = 2e9, v = t;
    while (v != s) {
        flow = min(cap[parent[v]][v], flow);
        v = parent[v];
    }
    // Mandamos flujo
    v = t;
    while (v != s) {
        cap[parent[v]][v] -= flow;
        //cap[v][parent[v]] += flow; // INVERSA
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
    int s, t, c, a, b, w, k = 1;
    cin >> n;
    while (n != 0) {
        cin >> s >> t >> c;
        adj.assign(n + 1, {});
        parent.assign(n + 1, 0);
        cap.assign(n + 1, vector<int>(n + 1));
        while (c--) {
            cin >> a >> b >> w;
            adj[a].insert(b);
            adj[b].insert(a);
            cap[a][b] += w;
            cap[b][a] += w;
        }
        cout << "Network " << k++ << '\n';
        cout << "The bandwidth is " << edmondsKarp(s, t) << ".\n\n";

        cin >> n;
    }
    return 0;
}