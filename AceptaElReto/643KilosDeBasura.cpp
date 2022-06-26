#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct res {
    ll cant;
    char tipo;
};

bool posible(ll k, vector<res> const& v, ll c1) {
    ll c2 = 2 * c1;

    ll used = 1, k1 = 0, k2 = 0;
    for (int i = 0; i < v.size() && used <= k; ++i) {
        if (v[i].tipo == 'E') {
            if (k2 + v[i].cant <= c2) k2 += v[i].cant;
            else {
                ++used;
                k2 = v[i].cant;
                k1 = 0;
            }
        }
        else {
            if (k1 + v[i].cant <= c1) k1 += v[i].cant;
            else {
                ++used;
                k1 = v[i].cant;
                k2 = 0;
            }
        }
    }

    return used <= k;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll k, n, x, ini, fin, ans, m;
    char c;
    cin >> k >> n;
    while (k) {
        vector<res> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].cant >> v[i].tipo;
        }

        ini = 0; fin = 2e9;
        for (int i = 0; i < n; ++i) {
            if (v[i].tipo == 'E') ini = max(ini, (v[i].cant + 1) / 2);
            else ini = max(ini, v[i].cant);
        }

        while (ini <= fin) {
            m = (ini + fin) / 2;

            if (posible(k, v, m)) {
                ans = m;
                fin = m - 1;
            }
            else ini = m + 1;
        }
        cout << ans << '\n';

        cin >> k >> n;
    }

    return 0;
}