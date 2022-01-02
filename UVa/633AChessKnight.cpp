#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> kx = { -1,-2,-2,-1,1,2,2,1 }, ky = { -2,-1,1,2,2,1,-1,-2 },
                  bx = { -2,-2,2,2 }, by = { -2,2,2,-2 };

int n;

//op == 0 es K, op == 1 es B, op == 2 es T
struct nodo {
    int x, y, op, d;
};

bool found(vector<vector<vector<bool>>> const& visited, int destx, int desty) {
    return visited[destx][desty][0] || visited[destx][desty][1] || visited[destx][desty][2];
}

bool inside(int x, int y) {
    return x > 0 && y > 0 && x <= 2 * n && y <= 2 * n;
}

int main() {
    std::ios::sync_with_stdio(false);
    int inix, iniy, destx, desty, x, y, sol;
    cin >> n;
    while (n != 0) {
        cin >> inix >> iniy >> destx >> desty;

        vector<vector<vector<bool>>> visited(2 * n + 1, vector<vector<bool>>(2 * n + 1, vector<bool>(3, false)));
        cin >> x >> y;
        while (x != 0) {
            visited[x][y][0] = true;
            visited[x][y][1] = true;
            visited[x][y][2] = true;
            cin >> x >> y;
        }

        visited[inix][iniy][0] = true;
        visited[inix][iniy][1] = true;
        visited[inix][iniy][2] = true;
        nodo act;
        sol = 1e9;
        queue<nodo> q;
        q.push({ inix, iniy, 0, 0});
        q.push({ inix, iniy, 1, 0 });
        q.push({ inix, iniy, 2, 0 });
        if (inix == destx && iniy == desty) sol = 0;
        while (!q.empty() && !found(visited, destx, desty)) {
            act = q.front();
            q.pop();

            if (act.op != 0) {
                for (int i = 0; i < 8; ++i) {
                    x = act.x + kx[i];
                    y = act.y + ky[i];
                    if (inside(x, y) && !visited[x][y][0]) {
                        visited[x][y][0] = true;
                        q.push({ x,y,0,act.d+1 });
                        if (x == destx && y == desty) sol = min(sol, act.d + 1);
                    }
                }
            }
            if (act.op != 1) {
                for (int i = 0; i < 4; ++i) {
                    x = act.x + bx[i];
                    y = act.y + by[i];
                    if (inside(x, y) && !visited[x][y][1]) {
                        visited[x][y][1] = true;
                        q.push({ x,y,1,act.d + 1 });
                        if (x == destx && y == desty) sol = min(sol, act.d + 1);
                    }
                }
            }
            if (act.op != 2) {
                //fila simetrica
                if (act.x > n) x = n - (act.x - n - 1);
                else x = n + (n - act.x + 1);
                y = act.y;
                if (inside(x, y) && !visited[x][y][2]) {
                    visited[x][y][2] = true;
                    q.push({ x,y,2,act.d + 1 });
                    if (x == destx && y == desty) sol = min(sol, act.d + 1);
                }
                //columna simetrica
                x = act.x;
                if (act.y > n) y = n - (act.y - n - 1);
                else y = n + (n - act.y + 1);
                if (inside(x, y) && !visited[x][y][2]) {
                    visited[x][y][2] = true;
                    q.push({ x,y,2,act.d + 1 });
                    if (x == destx && y == desty) sol = min(sol, act.d + 1);
                }
            }
        }

        if (sol != 1e9) cout << "Result : " << sol << '\n';
        else cout << "Solution doesn't exist\n";
        cin >> n;
    }
    return 0;
}