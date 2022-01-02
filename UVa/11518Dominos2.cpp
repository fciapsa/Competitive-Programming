#include <bits/stdc++.h>

using namespace std;
#define ll long long

int dfs(int v, vector<vector<int>> const& adyList, vector<bool>& visited) {
    int tam = 1;
    visited[v] = true;
    
    for (int w : adyList[v]) {
        if (!visited[w]) tam += dfs(w, adyList, visited);
    }

    return tam;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, l, tc, x, y, z, cont;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> l;
        vector<vector<int>> adyList(n);
        while (m--) {
            cin >> x >> y;
            adyList[x - 1].push_back(y - 1);
        }

        vector<bool> visited(n, false);
        cont = 0;
        while (l--) {
            cin >> z;
            if(!visited[z-1]) cont += dfs(z - 1, adyList, visited);
        }
        cout << cont << '\n';
    }

    return 0;
}