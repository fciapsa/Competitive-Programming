#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct interv {
    int ini, fin;
};

struct ordIni {
    bool operator()(interv const& i1, interv const& i2) {
        return i1.ini < i2.ini;
    }
};

struct ordFin {
    bool operator()(interv const& i1, interv const& i2) {
        return i1.fin < i2.fin;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        vector<interv> v1(n), v2;
        for (int i = 0; i < n; ++i) {
            cin >> v1[i].ini >> v1[i].fin;
        }
        v2 = v1;
        sort(v1.begin(), v1.end(), ordIni());
        sort(v2.begin(), v2.end(), ordFin());

        int ind1 = 0, ind2 = 0;
        int accum = 0, mx = 0, mx_t = 0, t_ini;
        while (ind1 < n) {
            while (v2[ind2].fin <= v1[ind1].ini) {
                if (accum == mx) {
                    mx_t += v2[ind2].fin - t_ini;
                }

                --accum;
                ++ind2;
            }

            ++accum;
            if (accum >= mx) {
                if (accum > mx) {
                    mx = accum;
                    mx_t = 0;
                }
                t_ini = v1[ind1].ini;
            }
            ++ind1;
        }
        while (ind2 < n) {
            if (accum == mx) {
                mx_t += v2[ind2].fin - t_ini;
            }

            --accum;
            ++ind2;
        }

        cout << mx << ' ' << mx_t << '\n';

        cin >> n;
    }

    return 0;
}