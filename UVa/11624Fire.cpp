#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0 , -1 };
int f, c;

struct nodo {
    int x, y, d;
    bool fire;
};

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < f&& y < c;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, sol, x, y;
    nodo act;
    cin >> tc;
    while (tc--) {
        cin >> f >> c;
        vector<vector<char>> mat(f, vector<char>(c));

        deque<nodo> q;
        vector<vector<bool>> visited(f, vector<bool>(c, false));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] == 'J') {
                    q.push_back({ i,j,0 ,false });
                    visited[i][j] = true;
                }
                else if (mat[i][j] == 'F') {
                    q.push_front({ i,j,0 ,true });
                    visited[i][j] = true;
                }
                else if (mat[i][j] == '#') visited[i][j] = true;
            }
        }

        sol = -1;
        while (!q.empty() && sol == -1) {
            act = q.front();
            q.pop_front();

            for (int i = 0; i < 4; ++i) {
                x = act.x + vx[i];
                y = act.y + vy[i];
                if (!act.fire) {
                    if (!inside(x, y)) sol = act.d + 1;
                    else {
                        if (!visited[x][y]) {
                            visited[x][y] = true;
                            q.push_back({ x,y,act.d + 1,false });
                        }
                    }
                }
                else {
                    if (inside(x, y) && !visited[x][y]) {
                        visited[x][y] = true;
                        q.push_back({ x,y,act.d + 1,true });
                    }
                }
            }
        }

        if (sol == -1) cout << "IMPOSSIBLE\n";
        else cout << sol << '\n';
    }
    return 0;
}