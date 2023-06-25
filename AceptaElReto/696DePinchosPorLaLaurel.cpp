#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x, tot, mn, mx;
    cin >> x;
    while (cin) {
        tot = mn = mx = x;
        cin >> x;
        while (x) {
            if (x < mn) mn = x;
            else if (x > mx) mx = x;
            tot += x;
            cin >> x;
        }

        cout << ((mx - mn + 1) * (mn+mx)) / 2 - tot << '\n';
        cin >> x;
    }

    return 0;
}