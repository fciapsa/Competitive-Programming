#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct punto {
    double x, y;
};

struct arista {
    int v1,v2;
    double cost;
    bool operator<(arista const& other) const {
        return cost < other.cost;
    }
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

int main() {
    std::ios::sync_with_stdio(false);
    int tc, s, p, x, y, se_pagan;
    double d;
    double dist;
    cin >> tc;
    while (tc--) {
        cin >> s >> p;
        vector<punto> pts(p);
        for (int i = 0; i < p; ++i) {
            cin >> x >> y;
            pts[i].x = x;
            pts[i].y = y;
        }

        vector<arista> edges;
        for (int i = 0; i < p; ++i) {
            for (int j = i + 1; j < p; ++j) {
                dist = hypot(pts[i].x - pts[j].x, pts[i].y - pts[j].y);
                edges.push_back({ i,j,dist });
            }
        }

        sort(edges.begin(), edges.end());
        UFDS uf(p);
        se_pagan = p - s;
        d = 0;
        if (se_pagan > 0) {
            for (arista a : edges) {
                if (uf.find(a.v1) != uf.find(a.v2)) {
                    uf.merge(a.v1, a.v2);
                    if (--se_pagan == 0) {
                        d = a.cost;
                        break;
                    }
                }
            }
        }

        cout << fixed << setprecision(2) << d << '\n';
    }
    return 0;
}