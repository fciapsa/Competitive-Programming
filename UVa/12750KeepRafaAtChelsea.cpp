#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, accum, ans;
    char r;
    cin >> tc;
    for (int k = 1; k <= tc; ++k) {
        cin >> n;
        accum = 0;
        ans = -1;
        for(int i = 1; i <=n;++i) {
            cin >> r;
            if (r == 'W')accum = 0;
            else {
                ++accum;
                if (accum == 3 && ans == -1) ans = i;
            }
        }

        cout << "Case " << k << ": ";
        if (ans == -1) cout << "Yay! Mighty Rafa persists!\n";
        else cout << ans << '\n';
    }

    return 0;
}