#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, mn, mx, prevMin, prevMax, mnDist;
    cin >> n;
    while (n) {
        cin >> x;
        mn = mx = x;
        mnDist = prevMin = prevMax = 0;
        for (int i = 1; i < n; ++i) {
            cin >> x;
            if (x > mx) {
                mx = x;
                prevMax = i;
                mnDist = i - prevMin;
            }
            else if (x == mx) {
                prevMax = i;
                mnDist = min(mnDist, i - prevMin);
            }

            if (x < mn) {
                mn = x;
                prevMin = i;
                mnDist = i - prevMax;
            }
            else if (x == mn) {
                prevMin = i;
                mnDist = min(mnDist, i - prevMax);
            }
        }
        cout << mn << ' ' << mx << ' ' << mnDist << '\n';
        cin >> n;
    }

    return 0;
}