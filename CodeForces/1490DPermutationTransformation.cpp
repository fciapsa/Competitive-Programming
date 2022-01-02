#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

void depth(vector<int> const& v, vector<int>& d, int ini, int fin, int lvl) {
    if (fin < ini) return;

    int max = -1, ind;
    for (int i = ini; i <= fin; ++i) {
        if (v[i] > max) {
            max = v[i];
            ind = i;
        }
    }

    d[ind] = lvl;
    depth(v, d, ini, ind - 1, lvl + 1);
    depth(v, d, ind + 1, fin, lvl + 1);
}

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n), d(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        depth(v, d, 0, n - 1, 0);
        cout << d[0];
        for (int i = 1; i < n; ++i) cout << ' ' << d[i];
        cout << '\n';
    }

    return 0;
}