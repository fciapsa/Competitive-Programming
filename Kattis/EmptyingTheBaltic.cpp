#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e9

vector<int> vx = { -1,-1,-1,0,1,1,1,0 }, vy = { -1,0,1,1,1,0,-1,-1 };

struct nodo {
    int x, y;
    ll drain;
    bool operator<(nodo const& other) const {
        return drain < other.drain;
    }
};

int h, w;
bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
}

int main() {
    std::ios::sync_with_stdio(false);
    int x, y;
    cin >> h >> w;

    vector<vector<ll>> mat(h, vector<ll>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> mat[i][j];

    vector<vector<ll>> drain(h, vector<ll>(w));
    cin >> x >> y;
    --x; --y;
    drain[x][y] = -mat[x][y];
    priority_queue<nodo> pq;
    pq.push({ x,y,-mat[x][y] });
    nodo act;
    while (!pq.empty()) {
        act = pq.top();
        pq.pop();

        if (act.drain < drain[act.x][act.y]) continue;

        for (int i = 0; i < 8; ++i) {
            x = act.x + vx[i];
            y = act.y + vy[i];
            if (inside(x, y)) {
                if (mat[x][y] < 0 && drain[act.x][act.y] > drain[x][y]) {
                    ll upd;
                    if (-mat[x][y] <= drain[act.x][act.y]) upd = -mat[x][y];
                    else upd = drain[act.x][act.y];
                    if (upd > drain[x][y]) {
                        drain[x][y] = upd;
                        pq.push({ x,y, upd });
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            ans += drain[i][j];

    cout << ans << '\n';

    return 0;
}