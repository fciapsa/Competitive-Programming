#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, c, d, dist, t;
    cin >> a >> b >> c >> d >> t;
    dist = abs(a - c) + abs(b - d);
    if (dist <= t && (t - dist) % 2 == 0) cout << "Y\n";
    else cout << "N\n";
    return 0;
}