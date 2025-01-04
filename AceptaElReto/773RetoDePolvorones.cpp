#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, p, tot;
    bool ok;
    cin >> n >> p;
    while (n) {
        tot = 0;
        vector<int> v(p), lim(p);
        for (int i = 0; i < p; ++i) {
            cin >> lim[i];
        }

        ok = true;
        for (int i = 0; i < p; ++i) {
            cin >> v[i];
            tot += v[i];
            if (lim[i] < v[i]) ok = false;
        }

        ok = ok && (tot <= n);

        if (ok) cout << "SI\n";
        else cout << "NO\n";

        cin >> n >> p;
    }

    return 0;
}