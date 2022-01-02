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
    int tc, c, d, v;
    char t1, t2;
    int a1, a2;
    cin >> tc;
    while (tc--) {
        cin >> c >> d >> v;
        vector<unordered_set<int>> fg(c + 1), cg(c + 1), fp(d + 1), cp(d + 1);
        M = N = 0;
        for (int i = 0; i < v; ++i) {
            cin >> t1 >> a1 >> t2 >> a2;
            if (t1 == 'C') {
                fg[a1].insert(M);
                cp[a2].insert(M);
                ++M;
            }
            else {
                fp[a1].insert(N);
                cg[a2].insert(N);
                ++N;
            }
        }

        grafo.assign(M, {});
        for (int i = 1; i <= c; ++i) {
            for (int vg : fg[i]) {
                for (int vp : cg[i]) {
                    grafo[vg].push_back(vp);
                }
            }
        }

        for (int i = 1; i <= d; ++i) {
            for (int vg : cp[i]) {
                for (int vp : fp[i]) {
                    grafo[vg].push_back(vp);
                }
            }
        }

        int mcbm = 0;
        match.assign(N + M, -1);
        for (int l = 0; l < M; ++l) {
            vis.assign(M, 0);
            mcbm += aug(l);
        }

        cout << N + M - mcbm << '\n';
    }
    return 0;
}