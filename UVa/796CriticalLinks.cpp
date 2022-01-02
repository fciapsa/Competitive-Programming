#include <bits/stdc++.h>

using namespace std;
#define ll long long

int hora;
set<pair<int, int>> puentes;

void dfs(int u, int uParent, vector<int> &horaVertice, vector<int> &alcanzable,
    vector<vector<int>> const& adyList) {

    horaVertice[u] = alcanzable[u] = hora;
    ++hora;
    for (int v: adyList[u]) {
        if (v == uParent) continue; // B.E. con el padre, que ignoramos
        if (horaVertice[v] == 0) { // No visitado
            dfs(v, u, horaVertice, alcanzable, adyList);
            if (alcanzable[v] > horaVertice[u]) {
                if (u < v) puentes.insert({ u,v });
                else puentes.insert({ v,u });
            }
            alcanzable[u] = min(alcanzable[u], alcanzable[v]);
        }
        else
            alcanzable[u] = min(alcanzable[u], horaVertice[v]); // B.E.
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, e, b;
    char c;
    cin >> n;
    while (cin) {
        vector<vector<int>> adyList(n);
        for (int i = 0; i < n; ++i) {
            cin >> a;
            cin >> c >> e >> c;
            while (e--) {
                cin >> b;
                adyList[a].push_back(b);
            }
        }

        hora = 1;
        vector<int> horaVertice(n);
        vector<int> alcanzable(n);
        puentes.clear();
        for (int i = 0; i < n; ++i) {
            if (horaVertice[i] == 0) dfs(i, 0, horaVertice, alcanzable, adyList);
        }

        cout << puentes.size() << " critical links\n";
        for (auto p : puentes) cout << p.first << " - " << p.second << '\n';
        cout << '\n';

    cin >> n;
    }
    return 0;
}