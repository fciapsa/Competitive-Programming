#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll n, blocks = 1, ans = 1;
    cin >> n;
    for (int i = 3; blocks + i * i <= n; i += 2) {
        blocks += i * i;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}