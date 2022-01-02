#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> hx = { -1,-2,-2,-1,1,2,2,1 };
const vector<int> hy = { -2,-1,1,2,2,1,-1,-2 };
const vector<int> kx = { -1,-1,-1,0,1,1,1,0 };
const vector<int> ky = { -1,0,1,1,1,0,-1,-1 };

int m, n;//filas y columnas

bool inside(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

struct pos {
    int x, y, dist;
};

int main() {
    std::ios::sync_with_stdio(false);
    int tc, x, y, ini_x, ini_y;
    cin >> tc;
    while (tc--) {
        cin >> m >> n;
        cin.ignore();

        vector<string> mat(m);
        for (int i = 0; i < m; ++i) getline(cin, mat[i]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'Z') {
                    for (int k = 0; k < hx.size(); ++k) {
                        x = i + hx[k];
                        y = j + hy[k];
                        if (inside(x, y) && mat[x][y] == '.') mat[x][y] = '#';
                    }
                    mat[i][j] = '#';
                }
                else if (mat[i][j] == 'A') {
                    ini_x = i;
                    ini_y = j;
                }
            }
        }

        pos act;
        bool found = false;
        int sol;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pos> q;
        q.push({ ini_x, ini_y, 0 });
        visited[ini_x][ini_y] = true;
        while (!found && !q.empty()) {
            act = q.front();
            q.pop();
            for (int k = 0; k < kx.size(); ++k) {
                x = act.x + kx[k];
                y = act.y + ky[k];
                if (inside(x, y) && !visited[x][y] && mat[x][y] != '#') {
                    if (mat[x][y] == 'B') {
                        found = true;
                        sol = act.dist + 1;
                        break;
                    }
                    else {
                        visited[x][y] = true;
                        q.push({ x,y,act.dist + 1 });
                    }
                }
            }
        }

        if (found) cout << "Minimal possible length of a trip is " << sol << '\n';
        else cout << "King Peter, you can't go now!\n";
    }
    return 0;
}