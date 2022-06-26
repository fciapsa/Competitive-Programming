#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct UFDS {
    vector<int> e;
    int sets;
    UFDS(int n) : e(n, -1), sets(n) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) {
        return e[x] < 0 ? x : find(e[x]);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        --sets;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct edge {
    int v1, v2, cost;
    bool operator<(edge const& other) const {
        return cost < other.cost;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, p, ans;
    cin >> n >> p;
    while (cin) {
        vector<edge> v(p);
        for (int i = 0; i < p; ++i) cin >> v[i].v1 >> v[i].v2 >> v[i].cost;

        sort(v.begin(), v.end());
        UFDS uf(n + 1);
        ans = 0;
        for (int i = 0; i < p && uf.sets > 2; ++i) {
            if (uf.join(v[i].v1, v[i].v2)) ans += v[i].cost;
        }

        if (uf.sets > 2) cout << "No hay puentes suficientes\n";
        else cout << ans << '\n';

        cin >> n >> p;
    }

    return 0;
}