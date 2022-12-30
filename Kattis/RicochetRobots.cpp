#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define ll long long
#define um unordered_map
#define INF 11

int n, w, h, l, ans = INF;
vector<string> mat;
um<int, um<int, um<int, um<int, um<int,int>>>>> state;

struct pos {
    int x, y;
    int posn() const {
        return x * w + y;
    }
    bool operator==(pos const& o) const {
        return x == o.x && y == o.y;
    }
    bool operator!=(pos const& o) const {
        return !(*this == o);
    }
};

vector<pos> robs = { {0,0}, {0,0}, {0,0}, {0,0} };
pos dest;

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
}

bool open(char c) {
    return c == '.' || c == 'X';
}

vector<int> vx = { -1,0,1,0 };
vector<int> vy = { 0,1,0,-1 };

void bt(int move) {
    if (move == ans) return;

    for (int i = 0; i < n; ++i) {
        pos ini = robs[i];
        for (int k = 0; k < 4; ++k) {
            pos temp = ini;
            pos next = { temp.x + vx[k], temp.y + vy[k] };
            while (in(next.x, next.y) && open(mat[next.x][next.y])) {
                temp = next;
                next.x += vx[k];
                next.y += vy[k];
            }

            if (temp != ini) {
                if (i == 0 && temp == dest) {
                    ans = move;
                    return;
                }
                robs[i] = temp;
                if (state[move][robs[0].posn()][robs[1].posn()][robs[2].posn()][robs[3].posn()] == 0) {
                    state[move][robs[0].posn()][robs[1].posn()][robs[2].posn()][robs[3].posn()] = 1;
                    mat[ini.x][ini.y] = '.';
                    mat[temp.x][temp.y] = char('1' + i);
                    bt(move + 1);
                    mat[ini.x][ini.y] = char('1' + i);
                    mat[temp.x][temp.y] = '.';
                }
                robs[i] = ini;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> w >> h >> l;
    mat.assign(h, "");
    for (int i = 0; i < h; ++i) cin >> mat[i];

    for(int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j) {
            switch (mat[i][j]) {
            case 'X': dest = { i,j }; break;
            case '1': robs[0] = { i,j }; break;
            case '2': robs[1] = { i,j }; break;
            case '3': robs[2] = { i,j }; break;
            case '4': robs[3] = { i,j }; break;
            }
        }
    }

    bt(1);

    if (ans == INF) cout << "NO SOLUTION\n";
    else cout << ans << '\n';

    return 0;
}