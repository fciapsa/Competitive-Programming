#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, e, a, b;
    bool ok;
    cin >> n;
    while (n != 0) {
        cin >> e;
        vector<vector<int>> adyList(n);

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            adyList[a].push_back(b);
            adyList[b].push_back(a);
        }

        int act;
        vector<int> color(n, -1);
        color[0] = 0;
        queue<int> q;
        q.push(0);
        ok = true;
        while (ok && !q.empty()) {
            act = q.front();
            q.pop();

            for (int v : adyList[act]) {
                if (color[v] == color[act]) {
                    ok = false;
                    break;
                }
                else if (color[v] == -1) {
                    color[v] = 1 - color[act];
                    q.push(v);
                }
            }
        }

        if (ok) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";

    cin >> n;
    }
    return 0;
}