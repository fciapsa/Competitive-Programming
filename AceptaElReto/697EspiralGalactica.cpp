#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> vx = { -1,0,1,0 }, vy = {0, 1, 0, -1};

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, y, dir, ans;
    bool ok;
    cin >> n;
    while (n) {
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v[i][j];
            }
        }

        x = y = n / 2;
        ans = v[x][y];
        dir = 0;
        ok = true;
        for (int cant = 1; ok; ++cant) {
            int aux = cant;
            while (aux--) {
                x += vx[dir];
                y += vy[dir];
                if (x < 0 || x == n || y < 0 || y == n) {
                    ok = false;
                    break;
                }
                ans += v[x][y];
            }
            dir = (dir + 1) % 4;
        }

        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}