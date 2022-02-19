#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct interv {
    int ini, fin;
    bool operator<(interv const& other)const {
        return ini < other.ini;
    }
    bool operator()(interv const& i1, interv const& i2)const {
        return i1.fin < i2.fin;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    vector<interv> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v1[i] = { a,a + b - 1 };
        v2[i] = v1[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), interv());
    vector<int> sol(n+1);
    int i = 1, j = 0;
    int k = 1, d = v1[0].ini;
    while (i < n) {
        if (v1[i].ini <= v2[j].fin) {
            while (i < n && v1[i].ini == d) {
                ++k;
                ++i;
            }
            if (i != n && v1[i].ini <= v2[j].fin) {
                sol[k] += v1[i].ini - d;
                ++k;
                d = v1[i].ini;
                ++i;
            }
        }
        else {
            sol[k] += v2[j].fin - d + 1;
            d = v2[j].fin + 1;
            while (j < n && v2[j].fin < d) {
                --k;
                ++j;
            }
        }
    }
    while (j < n) {
        sol[k] += v2[j].fin - d + 1;
        d = v2[j].fin + 1;
        while (j < n && v2[j].fin < d) {
            --k;
            ++j;
        }
    }

    cout << sol[1];
    for (int i = 2; i <= n; ++i) cout << ' ' << sol[i];
    cout << '\n';

    return 0;
}