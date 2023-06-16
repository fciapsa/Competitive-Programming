#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int c, m, n;
    cin >> c;
    while (cin) {
        cin >> m >> n;
        int mn, mx, prev, act, ch1, ch2;
        cin >> prev >> act;
        bool ok = true;
        ch1 = act - prev;
        mn = mx = ch1;
        for (int i = 2; i <= n; ++i) {
            prev = act;
            cin >> act;
            ch2 = act - prev;
            if (abs(ch1 - ch2) > c) ok = false;
            if (ch2 < mn) mn = ch2;
            if (ch2 > mx) mx = ch2;
            if (abs(mn - mx) > m) ok = false;
            ch1 = ch2;
        }
        if (ok) cout << "Ok\n";
        else cout << "Tropiezo\n";
        cin >> c;
    }

    return 0;
}