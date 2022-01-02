#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, v, e, a, b, n0, n1, sol, act;
    bool bipartite;
    cin >> tc;
    while (tc--) {
        cin >> v >> e;
        vector<vector<int>> adyList(v);
        while (e--) {
            cin >> a >> b;
            adyList[a].push_back(b);
            adyList[b].push_back(a);               
        }

        vector<int> color(v, -1);
        bipartite = true;
        sol = 0;
        for (int i = 0; i < v && bipartite; ++i) {
            if (color[i] == -1) {
                n0 = 1;
                n1 = 0;
                queue<int> q;
                color[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    act = q.front();
                    q.pop();

                    for (int w : adyList[act]) {
                        if (color[w] == -1) {
                            color[w] = 1 - color[act];
                            if (color[w] == 0) ++n0;
                            else ++n1;
                            q.push(w);
                        }
                        else if (color[w] == color[act]) bipartite = false;
                    }
                }

                if (n1 == 0) sol += n0;
                else sol += min(n0, n1);
            }
        }

        if (bipartite) cout << sol << '\n';
        else cout << "-1\n";
    }
    return 0;
}