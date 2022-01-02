#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int k, n, t, ans = -1, time = 0;
    char z;
    cin >> k >> n;
    while (n--) {
        cin >> t >> z;
        if (ans == -1) {
            time += t;
            if (time >= 210) ans = k;
            if (z == 'T') k = max(1, (k + 1) % 9);
        }
    }
    cout << ans << '\n';
    return 0;
}