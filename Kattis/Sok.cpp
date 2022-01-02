#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double a, b, c, i, j, k, ans;
    cin >> a >> b >> c >> i >> j >> k;
    ans = min(a / i, min(b / j, c / k));
    cout << a - ans * i << ' ' << b - ans * j << ' ' << c - ans * k << '\n';
    return 0;
}