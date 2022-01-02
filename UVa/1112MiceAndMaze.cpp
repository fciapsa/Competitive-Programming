#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct edge {
    int to, cost;
    bool operator<(edge const& other) const {
        return cost > other.cost;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, e, t, m, a, b, c, sol;
    bool first = true;
    edge act;
    cin >> tc;
    while (tc--) {
        cin >> n >> e >> t >> m;
        vector<vector<edge>> adyList(n + 1);
        while (m--) {
            cin >> a >> b >> c;
            //grafo inverso
            adyList[b].push_back({ a,c });
        }

        vector<int> dist(n + 1, 2e9);
        dist[e] = 0;
        priority_queue<edge> pq;
        pq.push({ e,0 });
        while (!pq.empty()) {
            act = pq.top();
            pq.pop();

            if (act.cost > dist[act.to]) continue;

            for (edge ed : adyList[act.to]) {
                if (dist[ed.to] > dist[act.to] + ed.cost) {
                    dist[ed.to] = dist[act.to] + ed.cost;
                    pq.push({ ed.to, dist[ed.to] });
                }
            }
        }

        sol = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] <= t) ++sol;
        }
        if (first) {
            first = false;
            cout << sol << "\n";
        }
        else cout << '\n' << sol << '\n';
    }
    return 0;
}