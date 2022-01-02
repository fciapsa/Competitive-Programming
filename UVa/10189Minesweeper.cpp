#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> vx = { -1,-1,-1,0,1,1,1,0 }, vy = { -1,0,1,1,1,0,-1,-1 };

int n, m;

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    std::ios::sync_with_stdio(false);   
    int x, y, caso = 1;
    bool first = true;
    cin >> n >> m;
    while (n != 0) {
        vector<vector<char>> mat(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] == '.') mat[i][j] = '0';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '*') {
                    for (int k = 0; k < 8; ++k) {
                        x = i + vx[k];
                        y = j + vy[k];
                        if (inside(x, y) && mat[x][y] != '*') ++mat[x][y];
                    }
                }
            }
        }

        if (first) first = false;
        else cout << '\n';
        cout << "Field #" << caso++ << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << mat[i][j];
            }
            cout << '\n';
        }


    cin >> n >> m;
    }
    return 0;
}