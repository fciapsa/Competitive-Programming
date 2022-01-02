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
    int n, a, b, cont;
    cin >> n;
    while (cin) {
        vector<string> mat(n);
        for (int i = 0; i < n; ++i) cin >> mat[i];

        vector<vector<int>> row_mark(n, vector<int>(n, -1)), col_mark(n, vector<int>(n, -1));
        a = cont = 0;
        while (a < n) {
            b = 0;
            while (b < n && mat[a][b] == 'X') ++b;
            while (b < n) {
                while (b < n && mat[a][b] == '.') {
                    row_mark[a][b] = cont;
                    ++b;
                }
                ++cont;
                while (b < n && mat[a][b] == 'X') ++b;
            }
            ++a;
        }
        M = cont;

        b = cont = 0;
        while (b < n) {
            a = 0;
            while (a < n && mat[a][b] == 'X') ++a;
            while (a < n) {
                while (a < n && mat[a][b] == '.') {
                    col_mark[a][b] = cont;
                    ++a;
                }
                ++cont;
                while (a < n && mat[a][b] == 'X') ++a;
            }
            ++b;
        }
        N = cont;

        grafo.assign(M, {});
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row_mark[i][j] != -1 && col_mark[i][j] != -1) 
                    grafo[row_mark[i][j]].push_back(col_mark[i][j]);
            }
        }

        int mcbm = 0;
        match.assign(N + M, -1);
        for (int l = 0; l < M; ++l) {
            vis.assign(M, 0);
            mcbm += aug(l);
        }
        cout << mcbm << '\n';

        cin >> n;
    }
    return 0;
}