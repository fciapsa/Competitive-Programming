#include <bits/stdc++.h>

using namespace std;
#define ll long long

int N, M;
vector<int> vis, match;
int aug(int l, vector<vector<int>> const& g) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int r : g[l]) {
        if (match[r] == -1 || aug(match[r], g)) {
            match[r] = l;
            return 1;
        }
    }

    return 0;
}

int berge_mcbm(vector<vector<int>> const& g) {
    int mcbm = 0;
    match.assign(N + M, -1);
    for (int l = 0; l < N; ++l) {
        vis.assign(N, 0);
        mcbm += aug(l, g);
    }
    return mcbm;
}

int main() {
    std::ios::sync_with_stdio(false);
    int m, a, b;
    cin >> N >> m;
    M = N;
    vector<vector<int>> g(N+M);
    while (m--) {
        cin >> a >> b;
        g[a].push_back(N+b);
    }

    if (berge_mcbm(g) == N) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}