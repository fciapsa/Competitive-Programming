#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double c, x, m, cost, time;
    cin >> c >> x >> m;
    vector<double> vf(6);
    int s, ans = -1;
    for (int i = 0; i < 6; ++i) {
        cin >> s >> vf[i];
        time = m / s;
        cost = time * x + m/vf[i];
        if (cost < c / 2) ans = s;
    }

    if (ans == -1) cout << "NO\n";
    else cout << "YES " << ans << '\n';

    return 0;
}