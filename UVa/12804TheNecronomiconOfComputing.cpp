#include <bits/stdc++.h>

using namespace std;
#define ll long long

enum tEstado { NUEVO, TOCADO, HUNDIDO };

bool ciclo;

void dfs(int u, vector<vector<int>> const& adyList, vector<tEstado> &estados) {
    estados[u] = TOCADO;

    for (int v : adyList[u]) {
        if (estados[v] == TOCADO) ciclo = true;
        else if(estados[v] == NUEVO) dfs(v, adyList, estados);
    }
    estados[u] = HUNDIDO;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, l, n;
    char c;
    cin >> tc;
    while (tc--) {
        cin >> l;
        vector<vector<int>> adyList(l + 2);
        for (int i = 1; i <= l; ++i) {
            cin >> c;
            if (c == 'A') adyList[i].push_back(i + 1);
            else {
                cin >> n;
                adyList[i].push_back(n);
                if (c == 'C') adyList[i].push_back(i+1);              
            }
        }

        vector<tEstado> estados(l + 2, NUEVO);
        ciclo = false;
        dfs(1, adyList, estados);
        if (estados[l+1] == NUEVO) cout << "NEVER\n";
        else if (ciclo) cout << "SOMETIMES\n";
        else cout << "ALWAYS\n";
    }
return 0;
}