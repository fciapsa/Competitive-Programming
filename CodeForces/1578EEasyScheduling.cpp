#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    ll tc, h, p, pot, sol, lvl, left;
    cin >> tc;
    while (tc--) {
        cin >> h >> p;
        pot = 1;
        lvl = 1;
        sol = 0;
        while (lvl <= h && pot < p) {
            ++sol;
            ++lvl;
            pot = min(2 * pot, p);
        }

        if (lvl <= h) {
            left = ((ll)1 << h) - ((ll)1 << (lvl-1));
            if (left % p) sol += left / p + 1;
            else sol += left / p;
        }
        cout << sol << '\n';

    }

    return 0;
}