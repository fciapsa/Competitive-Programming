#include <bits/stdc++.h>

using namespace std;
#define ll long long

int visited[10][10][10][10];

struct nodo {
    int digs[4];
    int d;
};

void sig(nodo const& act, nodo& next, int i, int j) {
    next = act;
    if (j == 0) next.digs[i] = (next.digs[i] + 9) % 10;
    else next.digs[i] = (next.digs[i] + 1) % 10;
}

bool iguales(int s[4], int t[4]) {
    return s[0] == t[0] && s[1] == t[1] && s[2] == t[2] && s[3] == t[3];
}

int main() {
    std::ios::sync_with_stdio(false);
    int s[4], t[4];
    int tc, n, sol, f1, f2, f3, f4;
    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 4; ++i) cin >> s[i];
        for (int i = 0; i < 4; ++i) cin >> t[i];

        memset(visited, 0, sizeof(visited));
        cin >> n;
        while (n--) {
            cin >> f1 >> f2 >> f3 >> f4;
            visited[f1][f2][f3][f4] = 1;
        }

        if (iguales(s,t)) sol = 0;
        else sol = -1;
        nodo act, next;
        queue<nodo> q;
        for (int i = 0; i < 4; ++i) act.digs[i] = s[i];
        act.d = 0;
        q.push(act);
        visited[s[0]][s[1]][s[2]][s[3]] = 1;
        while (!q.empty() && sol == -1) {
            act = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 2; ++j) {
                    sig(act, next, i, j);
                    if (!visited[next.digs[0]][next.digs[1]][next.digs[2]][next.digs[3]]) {
                        visited[next.digs[0]][next.digs[1]][next.digs[2]][next.digs[3]] = 1;
                        ++next.d;
                        q.push({ next });
                        if (iguales(next.digs,t)) {
                            sol = next.d;
                        }
                    }
                }
            }
        }

        if (sol != -1) cout << sol << '\n';
        else cout << "-1\n";
    }
    return 0;
}