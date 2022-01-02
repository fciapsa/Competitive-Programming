#include <bits/stdc++.h>

using namespace std;
#define ll long long

int f, c;//filas, columnas

const vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };

struct comp {
    char c;
    int tam;
    bool operator<(comp const& other)const {
        return tam > other.tam || (tam == other.tam && c < other.c);
    }
};

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < f && y < c;
}

int dfs(int x, int y, char c, vector<vector<char>> const& mat, vector<vector<bool>>& visited) {
    int tam = 1;
    visited[x][y] = true;

    int dx, dy;
    for (int i = 0; i < 4; ++i) {
        dx = x + vx[i];
        dy = y + vy[i];
        if (inside(dx, dy) && mat[dx][dy] == c && !visited[dx][dy]) {
            tam += dfs(dx, dy, c, mat, visited);
        }
    }

    return tam;
}

int main() {
    std::ios::sync_with_stdio(false);
    int k = 1;
    cin >> f >> c;
    while (f != 0) {
        vector<vector<char>> mat(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
            for(int j = 0; j < c; ++j)
            cin >> mat[i][j];
        }

        vector<comp> v;
        vector<vector<bool>> visited(f, vector<bool>(c, false));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                if (isalpha(mat[i][j]) && !visited[i][j]) {
                    char c = mat[i][j];
                    int tam = dfs(i, j, c, mat, visited);
                    v.push_back({ c,tam });
                }
            }
        }

        sort(v.begin(), v.end());
        cout << "Problem " << k++ << ":\n";
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i].c << ' ' << v[i].tam << '\n';
        }

        cin >> f >> c;
    }
    return 0;
}