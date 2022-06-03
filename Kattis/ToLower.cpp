#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int p, t, ans = 0;
    string s;
    bool pass, lows;
    cin >> p >> t;
    for (int i = 0; i < p; ++i) {
        pass = true;
        for (int j = 0; j < t; ++j) {
            cin >> s;
            if (pass) {
                lows = true;
                for (int k = 1; k < s.size() && lows; ++k) lows = islower(s[k]);
                if (!lows) pass = false;
            }
        }
        if (pass) ++ans;
    }
    cout << ans << '\n';

    return 0;
}