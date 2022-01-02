#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int l, x, a, ans = 0, in = 0;
    string s;
    cin >> l >> x;
    while (x--) {
        cin >> s >> a;
        if (s[0] == 'e') {
            if (in + a <= l) in += a;
            else ++ans;
        }
        else in -= a;
    }
    cout << ans << '\n';
    return 0;
}