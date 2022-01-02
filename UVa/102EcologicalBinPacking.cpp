#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int b1, g1, c1, b2, g2, c2, b3, g3, c3, s1, s2, s3, s4, s5, s6, mn;
    cin >> b1;
    while (cin) {
        cin >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
        s1 = b2 + b3 + c1 + c3 + g1 + g2;//BCG
        s2 = b2 + b3 + g1 + g3 + c1 + c2;//BGC
        s3 = c2 + c3 + b1 + b3 + g1 + g2;//CBG
        s4 = c2 + c3 + g1 + g3 + b1 + b2;//CGB
        s5 = g2 + g3 + b1 + b3 + c1 + c2;//GBC
        s6 = g2 + g3 + c1 + c3 + b1 + b2;//GCB

        mn = min(s1, min(s2, min(s3, min(s4, min(s5, s6)))));
        if (mn == s1) cout << "BCG " << mn << '\n';
        else if (mn == s2) cout << "BGC " << mn << '\n';
        else if (mn == s3) cout << "CBG " << mn << '\n';
        else if (mn == s4) cout << "CGB " << mn << '\n';
        else if (mn == s5) cout << "GBC " << mn << '\n';
        else cout << "GCB " << mn << '\n';

    cin >> b1;
    }
    return 0;
}