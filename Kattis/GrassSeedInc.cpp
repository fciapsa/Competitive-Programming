#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double c, w, l;
    int n;
    cin >> c >> n;
    double ans = 0.0;
    while (n--) {
        cin >> w >> l;
        ans += w * l;
    }

    cout << fixed << setprecision(7) << ans * c << '\n';

    return 0;
}