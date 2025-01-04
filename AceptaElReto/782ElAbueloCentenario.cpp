#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct trip {
    ll ini, fin, lim;
    bool operator<(trip const& o) const {
        return lim < o.lim;
    }
};

ll m, n, ans;
vector<trip> v;

void best(ll pos, ll ini, ll fin) {
    while (pos < v.size() && (v[pos].ini >= fin || v[pos].fin <= ini)) ++pos;
    ll lim = (pos < v.size()) ? v[pos].lim : n;

    ll cur = (fin - ini) * lim;
    if (cur > ans) ans = cur;

    if (pos < v.size()) {
        best(pos + 1, ini, v[pos].ini);
        best(pos + 1, v[pos].fin, fin);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    ll obs, y, x, w, h;
    char c;
    cin >> m >> n >> obs;
    while (m) {
        v.clear();
        for (int i = 0; i < obs; ++i) {
            cin >> c >> y >> x;
            x = n - x;
            if (c == 'G') v.push_back({ y,y,x });
            else {
                cin >> w >> h;
                v.push_back( { y,y + w,x });
            }
        }

        sort(v.begin(), v.end());
        if (obs == 0) cout << m * n << '\n';
        else {
            ans = 0;
            best(0, 0, m);
            cout << ans << '\n';
        }

        cin >> m >> n >> obs;
    }

    return 0;
}