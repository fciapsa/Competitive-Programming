#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct PushRelabel {
    struct Edge { int dest, back; ll f, c; };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vector<int>> hs; vector<int> H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
    void addEdge(int s, int t, ll cap, ll rcap = 0) {
        if (s == t) return;
        g[s].push_back({ t, (int)g[t].size(), 0, cap});
        g[t].push_back({ s, (int)g[s].size() - 1, 0, rcap});
    }
    void addFlow(Edge& e, ll f) {
        Edge& back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.
            dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    ll calc(int s, int t) {
        int v = g.size(); H[s] = v; ec[t] = 1;
        vector<int> co(2 * v); co[0] = v - 1;
        for(int i = 0; i < v; ++i) cur[i] = g[i].data();
        for (Edge& e : g[s]) addFlow(e, e.c);
        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)
                if (cur[u] == g[u].data() + g[u].size()) {
                    H[u] = 1e9;
                    for (Edge& e : g[u]) if (e.c && H[u] > H[e.
                        dest] + 1)
                        H[u] = H[e.dest] + 1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (int i = 0; i < v; ++i) if (hi < H[i] && H[i] < v)
                        --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                }
                else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= g.size(); }
};

int main() {
    std::ios::sync_with_stdio(false);
    int f, c, d, n;
    string pos;
    cin >> f >> c >> d;
    while (f || c || d) {
        cin >> n;

        PushRelabel pr(n + 5);
        int s = n, t = n + 1;
        pr.addEdge(n + 2, t, f);
        pr.addEdge(n + 3, t, c);
        pr.addEdge(n + 4, t, d);

        for (int i = 0; i < n; ++i) {
            pr.addEdge(s, i, 1);
            cin >> pos;
            for (char p : pos) {
                if (p == 'F') pr.addEdge(i, n + 2, 1);
                else if(p == 'C') pr.addEdge(i, n + 3, 1);
                else pr.addEdge(i, n + 4, 1);
            }
        }

        if (pr.calc(s, t) != f + c + d) cout << "NO\n";
        else cout << "SI\n";

        cin >> f >> c >> d;
    }

    return 0;
}