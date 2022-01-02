#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
    int x, y, sx, sy, ind;
};

struct ordInd {
    bool operator()(par const& p1, par const& p2) {
        return p1.ind < p2.ind;
    }
};

struct ordRow {
    bool operator()(par const& p1, par const& p2) {
        return p1.x < p2.x;
    }
};

struct ordCol {
    bool operator()(par const& p1, par const& p2) {
        return p1.y < p2.y;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int f, c, n, sf = 0, sc = 0, ind, prev;
    cin >> f >> c >> n;

    map<int, int> mpf;
    map<int, int> mpc;
    vector<par> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        v[i].ind = i;
        ++mpf[v[i].x];
        ++mpc[v[i].y];
    }

    sort(v.begin(), v.end(), ordRow());
    
    ind = 0;
    auto act1 = mpf.begin();
    sf = act1->first - 1;
    while (ind < n && act1 != mpf.end()) {
        if (v[ind].x > act1->first) {
            prev = act1->first;
            ++act1;
            sf += act1->first - prev - 1;
        }
        v[ind].sx = sf;
        ++ind;
    }

    sort(v.begin(), v.end(), ordCol());
    ind = 0;
    auto act = mpc.begin();
    sc = act->first - 1;
    while (ind < n && act != mpc.end()) {
        if (v[ind].y > act->first) {
            prev = act->first;
            ++act;
            sc += act->first - prev - 1;
        }
        v[ind].sy = sc;
        ++ind;
    }
    sort(v.begin(), v.end(), ordInd());
    for (int i = 0; i < n; ++i) {
        cout << v[i].x - v[i].sx << ' ' << v[i].y - v[i].sy << '\n';
    }

    return 0;
}