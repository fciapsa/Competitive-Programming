#include <bits/stdc++.h>

using namespace std;
#define ll long long

void dfs(int v, vector<vector<int>> const& adyList, vector<bool>& visited) {
    visited[v] = true;

    for (int w : adyList[v]) {
        if (!visited[w]) dfs(w, adyList, visited);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, ans;
    cin >> n;
    while (cin) {
        vector<vector<int>> adyList(n);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            adyList[i].push_back(x - 1);
            adyList[x-1].push_back(i);
        }

        ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(i, adyList, visited);
            }
        }
        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}