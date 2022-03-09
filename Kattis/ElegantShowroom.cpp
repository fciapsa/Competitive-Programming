#include <bits/stdc++.h>

using namespace std;
#define ll long long

int r, c;

struct pos {
    int x, y;
};

vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> r >> c;
    vector<string> mat(r);
    for (int i = 0; i < r; ++i) cin >> mat[i];

    pos act;
    cin >> act.x >> act.y;
    --act.x; --act.y;
    vector<vector<int>> dist(r, vector<int>(c, 1e9));
    dist[act.x][act.y] = 1;
    deque<pos> dq;
    dq.push_back(act);
    int x, y, w;
    while (!dq.empty()) {
        act = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; ++i) {
            x = act.x + vx[i];
            y = act.y + vy[i];
            if (in(x, y) && mat[x][y] != '#') {
                if (mat[x][y] == 'c') w = 1;
                else w = 0;

                if (dist[act.x][act.y] + w < dist[x][y]) {
                    dist[x][y] = dist[act.x][act.y] + w;
                    if (w == 0) dq.push_front({ x,y });
                    else dq.push_back({ x,y });
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < r; ++i) ans = min(ans, min(dist[i][0], dist[i][c - 1]));
    for (int j = 0; j < c; ++j) ans = min(ans, min(dist[0][j], dist[r-1][j]));
    cout << ans << '\n';
    return 0;
}