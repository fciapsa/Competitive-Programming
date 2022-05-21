#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, ans = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ans += x;
    }
    cout << ans - n + 1 << '\n';

    return 0;
}