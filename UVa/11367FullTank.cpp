#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct arista {
    int to, d;
};

struct nodo {
    int to, fuel, price;
    bool operator<(nodo const& other)const {
        return price > other.price;
    }
};

int dijkstra(int c, int s, int e, vector<vector<arista>> const& adyList, vector<int> const& prices) {
    vector<vector<int>> distTo(adyList.size(), vector<int>(c + 1, 1e9));
    priority_queue<nodo> pq;
    pq.push({ s,0,0 });
    distTo[s][0] = 0;
    nodo act;
    while (!pq.empty()) {
        act = pq.top();
        pq.pop();

        if (act.price > distTo[act.to][act.fuel]) continue;

        if (act.fuel < c && act.price + prices[act.to] < distTo[act.to][act.fuel + 1]) {
            distTo[act.to][act.fuel + 1] = act.price + prices[act.to];
            pq.push({ act.to, act.fuel + 1, distTo[act.to][act.fuel + 1] });
        }

        for (arista edg : adyList[act.to]) {
            if (act.fuel >= edg.d && act.price < distTo[edg.to][act.fuel - edg.d]) {
                distTo[edg.to][act.fuel - edg.d] = act.price;
                pq.push({ edg.to, act.fuel - edg.d, act.price });
            }
        }
    }

    if (distTo[e][0] != 1e9) return distTo[e][0];
    else return -1;

}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, u, v, d, q, c, s, e, sol;
    cin >> n >> m;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    vector<vector<arista>> adyList(n);
    while (m--) {
        cin >> u >> v >> d;
        adyList[u].push_back({ v,d });
        adyList[v].push_back({ u,d });
    }

    cin >> q;
    while (q--) {
        cin >> c >> s >> e;
        sol = dijkstra(c, s, e, adyList, prices);
        if (sol == -1) cout << "impossible\n";
        else cout << sol << '\n';
    }

    return 0;
}