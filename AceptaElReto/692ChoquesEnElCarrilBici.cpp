#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e18

struct bici {
    ll pos, v;
    bool operator<(bici const& o) const {
        return pos < o.pos;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        vector<bici> bicis(n);
        for (int i = 0; i < n; ++i) {
            cin >> bicis[i].pos >> bicis[i].v;
        }
        sort(bicis.begin(), bicis.end());

        ll ans = INF;
        for (int i = 1; i < bicis.size(); ++i) {
            if (bicis[i].pos == bicis[i - 1].pos) {
                ans = 0;
                break;
            }

            ll aux1 = bicis[i].pos - bicis[i - 1].pos;
            ll aux2 = bicis[i - 1].v - bicis[i].v;
            if (aux1 * aux2 > 0) ans = min(ans, aux1 / aux2);
        }

        if (ans != INF) cout << ans << '\n';
        else cout << "SIN COLISION\n";

        cin >> n;
    }

    return 0;
}