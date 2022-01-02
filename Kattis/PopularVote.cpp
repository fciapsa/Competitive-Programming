#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, mx, ind, v, tot;
    bool unique;
    cin >> tc;
    while (tc--) {
        cin >> n;
        mx = 0;
        tot = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> v;
            tot += v;
            if (v > mx) {
                mx = v;
                unique = true;
                ind = i;
            }
            else if (v == mx) unique = false;
        }

        if (unique) {
            if ((double)mx > tot / 2.0) cout << "majority winner " << ind << '\n';
            else cout << "minority winner " << ind << '\n';
        }
        else cout << "no winner\n";
    }

    return 0;
}