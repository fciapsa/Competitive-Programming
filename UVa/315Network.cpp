#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAX 101
int hora; int horaVertice[MAX]; int alcanzable[MAX];
int hijosRaiz;
unordered_set<int> crit;

void dfs(int u, int uParent, vector<unordered_set<int>> const&adyList) {
    horaVertice[u] = alcanzable[u] = hora; 
    ++hora;
    for (int v : adyList[u]) {
        if (v == uParent) continue;
        if (horaVertice[v] == 0) {
            if (uParent == 0) hijosRaiz++;
            dfs(v, u, adyList);
            if (alcanzable[v] >= horaVertice[u])
                if (uParent != 0) {
                    crit.insert(u);
                }
            alcanzable[u] = min(alcanzable[u], alcanzable[v]);
        }
        else
            alcanzable[u] = min(alcanzable[u], horaVertice[v]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;
    string s;
    cin >> n;
    while (n != 0) {
        vector<unordered_set<int>> adyList(n+1);

        getline(cin, s);
        getline(cin, s);
        while (s != "0") {
            stringstream ss(s);
            ss >> a;
            while (ss >> b) {//puede que guarde aristas repetidas, pero a lo sumo dos veces
                adyList[a].insert(b);
                adyList[b].insert(a);
            }
            getline(cin, s);
        }

        hora = 1;
        memset(horaVertice, 0, (n+1) * sizeof(horaVertice[0]));
        hijosRaiz = 0;
        crit.clear();
        dfs(1, 0, adyList);
        if (hijosRaiz > 1) crit.insert(1);

        cout << crit.size() << '\n';
    cin >> n;
    }
    return 0;
}