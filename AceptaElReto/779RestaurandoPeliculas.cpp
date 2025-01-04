#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
    int ini, fin;
    bool operator<(par const& o) const {
        return ini < o.ini || (ini == o.ini && fin > o.fin);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int tot, n, m, ini, fin;
    char c;
    cin >> tot >> n;
    while (n) {
        vector<par> v;

        for (int i = 0; i < n; ++i) {
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> ini >> c >> fin;
                v.push_back({ ini,fin });
            }
        }
        sort(v.begin(), v.end());

        int ind1 = 1, hasta = v[0].fin;
        bool ok = v[0].ini == 1;
        while (ok && ind1 < v.size()) {
            if (v[ind1].ini <= hasta + 1) {
                hasta = max(hasta, v[ind1].fin);
                ++ind1;
            }
            else ok = false;
        }

        if (v[0].ini == 1 && hasta == tot) cout << "SI\n";
        else cout << "NO\n";
        cin >> tot >> n;
    }

    return 0;
}