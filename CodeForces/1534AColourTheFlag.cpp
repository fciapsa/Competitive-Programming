#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

vector<int> vx = { -1, 0,1,0 };
vector<int> vy = { 0,1,0,-1 };

struct coord {
    int x, y;
};

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, m, x, y;
    bool ok;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));

        ok = true;
        x = 0;
        y = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] != '.') {
                    x = i;
                    y = j;
                }
            }
        }

        if (mat[x][y] == '.') mat[x][y] = 'R';
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[x][y] = true;
        queue<coord> q;
        q.push({ x,y });
        coord pos;
        while (ok && !q.empty()) {
            pos = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                x = pos.x + vx[d];
                y = pos.y + vy[d];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    if (mat[x][y] == mat[pos.x][pos.y]) {
                        ok = false;
                        break;
                    }
                    else if (mat[x][y] == '.') {
                        if (mat[pos.x][pos.y] == 'R') mat[x][y] = 'W';
                        else mat[x][y] = 'R';
                    }
                    q.push({ x,y });
                }
            }
        }


        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << mat[i][j];
                }
                cout << '\n';
            }
        }
        else cout << "NO\n";
    }

    return 0;
}