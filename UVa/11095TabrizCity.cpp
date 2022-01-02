#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m, mvc, best_set;
vector<int> adyMat;
map<int, int> mp;

int backtrack(int lvl, int mask, int n_selected, int selected_v) {
    if (mask == 0) {//ya no se puede seleccionar ningun vertice
        if (n - n_selected < mvc) {//MVC = n - MIS
            mvc = n - n_selected;
            best_set = ~selected_v;
        }
        return n-n_selected;
    }

    if (mp.count(mask)) return mp[mask];

    int m1 = mask, pow2, v, aux = 31;
    while (m1 && lvl - n_selected + 1 < mvc) {
        pow2 = m1 & (-m1);
        v = __builtin_ctz(m1);
        m1 -= pow2;
        if (v < lvl) continue;//no contar 2 veces
        aux = min(aux, backtrack(lvl + 1, mask & (~adyMat[v]), n_selected + 1, selected_v | pow2));
    }
    return mp[mask] = aux;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, a, b, k = 1;
    bool first;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        adyMat.assign(n,0);
        for (int i = 0; i < n; ++i) adyMat[i] |= (1 << i);
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            adyMat[a] |= (1 << b);
            adyMat[b] |= (1 << a);
        }

        mvc = n;
        best_set = (1 << n) - 1;
        mp.clear();
        backtrack(0,(1<<n) - 1, 0, 0);

        cout << "Case #" << k++ << ": " << mvc << '\n';
        first = true;
        for (int pos = 1, v = 0; v < n; pos = pos << 1, ++v) {
            if (pos & best_set) {
                if (first) first = false;
                else cout << ' ';
                cout << v;
            }
        }
        cout << '\n';
    }
    return 0;
}