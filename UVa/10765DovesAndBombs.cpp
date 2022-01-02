#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct target {
    int v, pigeon;
    bool operator<(target const& other) const {
        return pigeon > other.pigeon || (pigeon == other.pigeon && v < other.v);
    }
};

#define MAX_V 10002
int hora; int horaVertice[MAX_V]; int alcanzable[MAX_V];
bool isArtic[MAX_V];
int hijosRaiz;

void dfs(int u, int uParent, vector<vector<int>> const& adyList, vector<target>& sol) {
    horaVertice[u] = alcanzable[u] = hora; hora++;
    int comps = 0;
    for (int v : adyList[u]) {
        if (v == uParent) continue;
        if (horaVertice[v] == 0) {
            if (uParent == -1) hijosRaiz++;
            dfs(v, u, adyList, sol);
            if (alcanzable[v] >= horaVertice[u])
                if (uParent != -1) {
                    isArtic[u] = true;
                    ++comps;
                }
            alcanzable[u] = min(alcanzable[u], alcanzable[v]);
        }
        else
            alcanzable[u] = min(alcanzable[u], horaVertice[v]);
    }

    if (isArtic[u]) sol.push_back({ u,comps + 1 });
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, a, b, ind;
    cin >> n >> m;
    while (n != 0) {
        vector<vector<int>> adyList(n);
        cin >> a >> b;
        while (a != -1) {
            adyList[a].push_back(b);
            adyList[b].push_back(a);
            cin >> a >> b;
        }

        vector<target> sol;
        hora = 1;
        memset(horaVertice, 0, n * sizeof(horaVertice[0]));
        memset(isArtic, false, n * sizeof(isArtic[0]));
        hijosRaiz = 0;
        dfs(0, -1, adyList, sol);
        if (hijosRaiz > 1) {
            sol.push_back({ 0,hijosRaiz });
            isArtic[0] = true;
        }

        sort(sol.begin(), sol.end());
        ind = 0;
        while (sol.size() < m) {
            while (isArtic[ind]) ++ind;
            sol.push_back({ ind, 1 });
            isArtic[ind] = true;
        }

        for (int i = 0; i < m; ++i) cout << sol[i].v << ' ' << sol[i].pigeon << '\n';
        cout << '\n';

        cin >> n >> m;
    }
    return 0;
}