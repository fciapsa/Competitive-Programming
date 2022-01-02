#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double p, a, b, c, d;
    int n;
    cin >> p >> a >> b >> c >> d >> n;
    vector<double> v(n+1);
    for (int i = 1; i <= n; ++i) {
        v[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
    }

    double mn = v[n], ans = -1e9;

    for (int i = n-1; i >= 1; --i) {
        ans = max(ans, v[i] - mn);
        mn = min(mn, v[i]);
    }
    cout << fixed << setprecision(6) << max(ans,0.0) << '\n';
    return 0;
}