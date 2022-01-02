#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    char t, b, l, r;
    int n1 = 0, n2 = 0, sw;
    cin >> n;
    while (n--) {
        cin >> t >> b >> l >> r;
        if (t == '0') ++n1;
        if (b == '0') ++n1;
        if (l == '0') ++n2;
        if (r == '0') ++n2;
    }
    sw = min(n1 / 2, n2 / 2);
    cout << sw << ' ' << n1 - 2 * sw << ' ' << n2 - 2 * sw << '\n';
    return 0;
}