#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int m, p, l, e, r, s, n, sm;
    cin >> m;
    while (cin) {
        cin >> p >> l >> e >> r >> s >> n;
        while (n--) {
            sm = p / s;
            p = l / r;
            l = m * e;
            m = sm;
        }
        cout << m << '\n';
        cin >> m;
    }
    return 0;
}