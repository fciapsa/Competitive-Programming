#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> vx = { -1,0,1,0 };
vector<int> vy = { 0,1,0,-1 };

int c, f;

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < f && y < c;
}

struct pt {
    int x, y;
};

int main() {
    std::ios::sync_with_stdio(false);
    int ini, fin, m, ans1, ans2, need, cubiertas;
    pt start, act, nxt;
    cin >> c >> f;
    while (cin) {
        vector<vector<int>> mat(f, vector<int>(c));
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                cin >> mat[i][j];

        start = { f / 2, 0 };
        need = (c * f) / 2;
        ini = 0, fin = 1000;
        while (ini <= fin) {
            m = (ini + fin) / 2;

            vector<vector<bool>> marks(f, vector<bool>(c, false));
            marks[start.x][start.y] = true;
            cubiertas = 1;
            queue<pt> q;
            q.push(start);
            while (!q.empty()) {
                act = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    nxt.x = act.x + vx[k];
                    nxt.y = act.y + vy[k];
                    if (in(nxt.x, nxt.y) && !marks[nxt.x][nxt.y]) {
                        marks[nxt.x][nxt.y] = true;
                        if (mat[nxt.x][nxt.y] <= m) {
                            ++cubiertas;
                            q.push(nxt);
                        }
                    }
                }
            }

            if (cubiertas > need) {
                ans1 = m;
                ans2 = cubiertas;
                fin = m - 1;
            }
            else ini = m + 1;
        }
        cout << ans1 << ' ' << ans2 << '\n';

        cin >> c >> f;
    }

    return 0;
}