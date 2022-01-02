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
    int tc, n, m, s, t, p, u, v, c, mx;
    edge act;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> s >> t >> p;
        vector<vector<edge>> adyList(n + 1), adyListInv(n + 1);
        while (m--) {
            cin >> u >> v >> c;
            adyList[u].push_back({ v,c });
            adyListInv[v].push_back({ u,c });
        }

        vector<int> distFromS(n + 1, 1e9);
        distFromS[s] = 0;
        priority_queue<edge> pq;
        pq.push({ s,0 });
        while (!pq.empty()) {
            act = pq.top();
            pq.pop();

            if (act.cost > distFromS[act.to]) continue;

            for (edge edg : adyList[act.to]) {
                if (distFromS[edg.to] > distFromS[act.to] + edg.cost) {
                    distFromS[edg.to] = distFromS[act.to] + edg.cost;
                    pq.push({ edg.to, distFromS[edg.to] });
                }
            }
        }

        vector<int> distToT(n + 1, 1e9);
        distToT[t] = 0;
        priority_queue<edge> pq2;
        pq2.push({ t,0 });
        while (!pq2.empty()) {
            act = pq2.top();
            pq2.pop();

            if (act.cost > distToT[act.to]) continue;

            for (edge edg : adyListInv[act.to]) {
                if (distToT[edg.to] > distToT[act.to] + edg.cost) {
                    distToT[edg.to] = distToT[act.to] + edg.cost;
                    pq2.push({ edg.to, distToT[edg.to] });
                }
            }
        }

        //recorrer todas las aristas y hacer el maximo de las que estan en un camino valido
        mx = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < adyList[i].size(); ++j) {
                act = adyList[i][j];
                if (distFromS[i] + distToT[act.to] + act.cost <= p) mx = max(mx, act.cost);
            }
        }

        cout << mx << '\n';
    }

    return 0;
}