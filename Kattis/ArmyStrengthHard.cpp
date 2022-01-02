#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int t, ng, nm, maxg, maxm, x;
    cin >> t;
    while (t--) {
        cin >> ng >> nm;
        maxg = -1;
        maxm = -1;
        while (ng--) {
            cin >> x;
            maxg = max(x, maxg);
        }
        while (nm--) {
            cin >> x;
            maxm = max(x, maxm);
        }

        if (maxg >= maxm) cout << "Godzilla\n";
        else cout << "MechaGodzilla\n";
    }

    return 0;
}