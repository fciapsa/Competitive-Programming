#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    double x, y, h1, h2, ans;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        ans = 0;
        h1 = ((x + y) + sqrt(x * x - x * y + y * y)) / 6;
        h2 = ((x + y) - sqrt(x * x - x * y + y * y)) / 6;
        if (h1 > 0 && x > 2 * h1 && y > 2 * h1) ans = fmax(ans, (x - 2 * h1) * (y - 2 * h1) * h1);
        if (h2 > 0 && x > 2 * h2 && y > 2 * h2) ans = fmax(ans, (x - 2 * h2) * (y - 2 * h2) * h2);
        cout << fixed << setprecision(8) << ans << '\n';
    }

    return 0;
}