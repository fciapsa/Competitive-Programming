#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int e, n, t, to, source, mx, mx_d, act;
    cin >> e;
    vector<vector<int>> adyList(e);
    for (int i = 0; i < e; ++i) {
        cin >> n;
        while (n--) {
            cin >> to;
            adyList[i].push_back(to);
        }
    }

    cin >> t;
    while (t--) {
        cin >> source;
        vector<int> lvl(e, -1);
        vector<int> lvl_count(e, 0);
        lvl[source] = 0;
        mx = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            act = q.front();
            q.pop();

            for (int v : adyList[act]) {
                if (lvl[v] == -1) {
                    lvl[v] = lvl[act] + 1;
                    ++lvl_count[lvl[v]];
                    q.push(v);
                }
            }
        }

        for (int i = 1; i < e && lvl_count[i] != 0; ++i) {
            if (lvl_count[i] > mx) {
                mx = lvl_count[i];
                mx_d = i;
            }
        }
        
        if (mx == 0) cout << "0\n";
        else cout << mx << ' ' << mx_d << '\n';
    }

    return 0;
}