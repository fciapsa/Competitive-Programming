#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

struct player {
    ll id, tok;
    bool operator<(player const& other) const {
        return tok < other.tok;
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, ind;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<player> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].tok;
            v[i].id = i+1;
        }

        sort(v.begin(), v.end());

        vector<bool> can(n + 1, false);
        vector<ll> accum(n, 0);
        accum[0] = v[0].tok;
        for (int i = 1; i < n; ++i) accum[i] = accum[i-1] + v[i].tok;
        ind = 0;
        for (int i = 0; i < n-1; ++i) {
            if (accum[i] >= v[i+1].tok) continue;
            ind = i + 1;
        }

        cout << n - ind << '\n';
        for (int i = ind; i < n; ++i) can[v[i].id] = true;
        bool first = true;
        for (int i = 1; i <= n; ++i) {
            if (can[i]) {
                if (first) {
                    first = false;
                    cout << i;
                }
                else cout << ' ' << i;
            }
        }
        cout << '\n';
    }

    return 0;
}