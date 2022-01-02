#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

vector<int> vx = { -1, -1, 0 , 1,1,1,0,-1 };
vector<int> vy = { 0, 1 ,1,1,0,-1,-1,-1 };

int main() {
    std::ios::sync_with_stdio(false);

    int tc, h, w, x, y;
    bool ok;
    cin >> tc;
    while (tc--) {
        cin >> h >> w;
        vector<vector<char>> mat(h, vector<char>(w, '0'));
        for (int j = 0; j < w; ++j) { // first row
            ok = true;
            for (int dir = 0; dir < 8 && ok; ++dir) {
                x = vx[dir];
                y = j + vy[dir];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    ok = mat[x][y] == '0';
                }
            }
            if (ok) mat[0][j] = '1';
        }
        for (int i = 1; i < h; ++i) { //last column
            ok = true;
            for (int dir = 0; dir < 8 && ok; ++dir) {
                x = i + vx[dir];
                y = w - 1 + vy[dir];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    ok = mat[x][y] == '0';
                }
            }
            if (ok) mat[i][w-1] = '1';
        }
        for (int j = w - 1; j >= 0; --j) {//last row
            ok = true;
            for (int dir = 0; dir < 8 && ok; ++dir) {
                x = h-1+ vx[dir];
                y = j + vy[dir];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    ok = mat[x][y] == '0';
                }
            }
            if (ok) mat[h-1][j] = '1';
        }
        for (int i = h - 1; i > 0; --i) {//first column
            ok = true;
            for (int dir = 0; dir < 8 && ok; ++dir) {
                x = i + vx[dir];
                y = vy[dir];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    ok = mat[x][y] == '0';
                }
            }
            if (ok) mat[i][0] = '1';
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << mat[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}