#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1000000

struct nodo {
    int v;
    ll mx;
};

struct UFDS {
    vector<int> p;
    int numSets;
    UFDS(int n) : p(n, 0), numSets(n) {
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        p[i] = j;
        --numSets;
    }
};

struct edge {
    int a, b;
    ll d;
    bool operator<(edge const& other)const {
        return d < other.d;
    }
    int other(int x) {
        if (x == a) return b;
        return a;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, r, a, b, l, caso = 1, q, ini, fin, sol;
    cin >> tc;
    while (tc--) {
        cin >> n >> r;

        vector<edge> aristas(r);
        for(int i = 0; i < r; ++i) cin >> aristas[i].a >> aristas[i].b >> aristas[i].d;
        sort(aristas.begin(), aristas.end());

        vector<edge> mst;
        UFDS uf(n);
        for (int i = 0; i < r; ++i) {
            if (uf.find(aristas[i].a - 1) != uf.find(aristas[i].b - 1)) {
                uf.merge(aristas[i].a - 1, aristas[i].b - 1);
                mst.push_back(aristas[i]);
                if (uf.numSets == 1) break;
            }
        }

        vector<vector<edge>> adyList(n + 1);
        for (int i = 0; i < mst.size(); ++i) {
            adyList[mst[i].a].push_back(mst[i]);
            adyList[mst[i].b].push_back(mst[i]);
        }

        cout << "Case " << caso++ << '\n';
        cin >> q;
        while (q--) {
            cin >> ini >> fin;
            queue<nodo> cola;
            vector<bool> visited(n + 1, false);
            visited[ini] = true;
            cola.push({ ini, 0});
            nodo act;
            while (!cola.empty()) {
                act = cola.front();
                cola.pop();

                for (edge e : adyList[act.v]) {
                    if (!visited[e.other(act.v)]) {
                        visited[e.other(act.v)] = true;
                        if (e.other(act.v) == fin) {
                            sol = max(act.mx, e.d);
                            break;
                        }
                        else cola.push({ e.other(act.v), max(act.mx, e.d) });
                    }
                }
            }

            cout << sol << '\n';
        }
        cout << '\n';
    }
    return 0;
}