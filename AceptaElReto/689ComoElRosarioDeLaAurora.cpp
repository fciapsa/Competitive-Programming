#include <bits/stdc++.h>

using namespace std;
#define ll long long

int tam, col;
vector<bool> vis;
vector<vector<int>> adyList;

void dfs(int x, int c) {
    vis[x] = true;
    ++tam;
    if (c == 0) ++col;

    for (int y : adyList[x]) {
        if (!vis[y]) dfs(y, 1 - c);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, p, a, x, y;
    cin >> n;
    while (cin) {
        cin >> p >> a;
        adyList.assign(n + 1, {});
        for (int i = 0; i < p; ++i) {
            cin >> x >> y;
            adyList[x].push_back(y);
            adyList[y].push_back(x);
        }

        vector<pair<int, int>> comps;
        vis.assign(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                tam = col = 0;
                dfs(i, 0);
                comps.push_back({ col, tam - col });
            }
        }

        vector<vector<int>> dp(comps.size(), vector<int>(a + 1, 0));
        for (int j = 0; j <= a; ++j) {
            if (j >= comps[0].first) dp[0][j] = comps[0].first;
            if (j >= comps[0].second) dp[0][j] = max(dp[0][j], comps[0].second);
        }

        for (int i = 1; i < comps.size(); ++i) {
            for (int j = 0; j <= a; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= comps[i].first) dp[i][j] = max(dp[i][j], comps[i].first + dp[i - 1][j - comps[i].first]);
                if (j >= comps[i].second) dp[i][j] = max(dp[i][j], 
                    comps[i].second + dp[i - 1][j - comps[i].second]);
            }
        }
        cout << dp[comps.size() - 1][a] << '\n';

        cin >> n;
    }

    return 0;
}