#include <bits/stdc++.h>

using namespace std;
#define ll long long

int M, N;//M parte izquierda, N parte derecha
vector<vector<int>> grafo; // dirigido, tamaño M
vector<int> match, vis;

int aug(int l) {//devuelve 1 si encuentra un augmenting path
                //para el matching M representado en match
    if (vis[l]) return 0;
    vis[l] = 1;
    for (auto r : grafo[l]) {
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int nk, np, mcbm, total, nki, id;
    cin >> nk >> np;
    while (nk != 0) {
        total = 0;
        id = 0;
        map<int, vector<int>> categ_a_nodos;
        map<int, int> nodo_a_categ;
        grafo = {};
        for (int i = 0; i < nk; ++i) {
            cin >> nki;
            total += nki;
            for (int j = id; j < id + nki; ++j) {
                grafo.push_back({});
                categ_a_nodos[i].push_back(j);
                nodo_a_categ[j] = i;
            }
            id = total;
        }
        M = total;
        N = np;

        for (int i = 0; i < N; ++i) {
            cin >> nki;
            for (int j = 0; j < nki; ++j) {
                cin >> id;
                for (int v : categ_a_nodos[id-1]) {
                    grafo[v].push_back(i);
                }
            }
        }

        mcbm = 0;
        match.assign(N, -1);
        for (int l = 0; l < M; ++l) {
            vis.assign(M, 0);
            mcbm += aug(l);
        }
        if (mcbm != total) cout << "0\n";
        else {
            cout << "1\n";
            map<int, vector<int>> categ_to_problems;
            for (int i = 0; i < N; ++i) {
                if (match[i] != -1) {
                    categ_to_problems[nodo_a_categ[match[i]]].push_back(i + 1);
                }
            }
            for (int i = 0; i < nk; ++i) {
                cout << categ_to_problems[i][0];
                for (int j = 1; j < categ_to_problems[i].size(); ++j) cout << ' ' << categ_to_problems[i][j];
                cout << '\n';
            }
        }

    cin >> nk >> np;
    }

    return 0;
}