#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, c, prev, act, ans;
    cin >> a >> c;
    while (a != 0) {
        ans = 0;
        cin >> act;
        for (int i = 1; i < c; ++i) {
            prev = act;
            cin >> act;
            if (act > prev) ans += act - prev;
        }
        ans += a - act;
        cout << ans << '\n';
        cin >> a >> c;
    }
    return 0;
}