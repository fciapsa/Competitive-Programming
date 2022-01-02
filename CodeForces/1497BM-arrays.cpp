#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, m, sol, ind, cx, cy;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<int> v(n);
        vector<int> mods(m);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            v[i] %= m;
            ++mods[v[i]];
        }

        sol = 0;
        if (mods[0] > 0) ++sol;
        for (int i = 1; i < m; ++i) {
            if (mods[i] > 0) {
                cx = mods[i];
                cy = mods[m - i];
                if (cx < cy) sol += 1 + (cy - cx - 1);
                else if (cx == cy) ++sol;
                else sol += 1 + (cx - cy - 1);

                mods[i] = 0;
                mods[m - i] = 0;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}