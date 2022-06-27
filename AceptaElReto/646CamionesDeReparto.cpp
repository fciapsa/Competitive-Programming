#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct edge {
    int to, c;
};

int main() {
    std::ios::sync_with_stdio(false);
    int v, e, a, b, c, k, ini, fin, ancho, act;
    bool reached;
    cin >> v;
    while (cin) {
        cin >> e;
        vector<vector<edge>> adyList(v + 1);
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> c;
            adyList[a].push_back({ b,c });
            adyList[b].push_back({ a,c });
        }

        cin >> k;
        while (k--) {
            cin >> ini >> fin >> ancho;
            vector<bool> visited(v + 1, false);
            queue<int> q;
            q.push(ini);
            visited[ini] = true;
            reached = false;
            while (!q.empty() && !reached) {
                act = q.front();
                q.pop();

                for (edge ed : adyList[act]) {
                    if (!visited[ed.to] && ed.c >= ancho) {
                        if (ed.to == fin) reached = true;
                        visited[ed.to] = true;
                        q.push(ed.to);
                    }
                }
            }

            if (reached) cout << "SI\n";
            else cout << "NO\n";
        }


        cin >> v;
    }

    return 0;
}