#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long

const ll K = 1048576; //2^20

struct trip {
    ll lvl, pos;
};

int main() {
    std::ios::sync_with_stdio(false);
    ll lvls, c1, c2, bot, inv, ind;
    cin >> lvls;
    while (cin) {
        cin >> c1 >> c2 >> bot >> inv;
        vector<ll> vini((lvls * (lvls + 1)) / 2, 0);

        ind = 0;
        for (int i = 0; i < lvls; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i % 2 == 0) vini[ind] = c1 * K;
                else vini[ind] = c2 * K;
                ++ind;
            }
        }

        bot *= K;
        ll ini = 0, fin = 1e9, ret = -1, m;
        while (ini <= fin) {
            m = (ini + fin) / 2;

            vector<ll> v = vini;
            vector<bool> vis(v.size(), false);
            ll cont = 0;
            queue<trip> q;
            q.push({ 1,0 });
            vis[0] = true;
            v[0] -= (bot * m);
            while (!q.empty()) {
                trip act = q.front();
                q.pop();

                if (v[act.pos] > 0) continue;

                ++cont;
                ll val = (-v[act.pos]) / 2;
                if (val && act.lvl + 1 <= lvls) {
                    v[act.pos + act.lvl] -= val;
                    v[act.pos + act.lvl + 1] -= val;
                    if (!vis[act.pos + act.lvl]) {
                        vis[act.pos + act.lvl] = true;
                        q.push({ act.lvl + 1, act.pos + act.lvl });
                    }
                    if (!vis[act.pos + act.lvl + 1]) {
                        vis[act.pos + act.lvl + 1] = true;
                        q.push({ act.lvl + 1, act.pos + act.lvl + 1 });
                    }
                }
            }

            if (cont >= inv) {
                ret = m;
                fin = m - 1;
            }
            else ini = m + 1;
        }

        cout << ret << '\n';

        cin >> lvls;
    }

    return 0;
}