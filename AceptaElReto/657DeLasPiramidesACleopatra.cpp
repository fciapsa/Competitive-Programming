#include <bits/stdc++.h>

using namespace std;
#define ll long long

int dif(int a, int b) {
    int ret = abs(a - b);
    if (a < 0 && b > 0) return ret - 1;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, a, b, c, dif1, dif2;
    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        dif1 = dif(a, b);
        dif2 = dif(b, c);
        if (dif1 == dif2) cout << "EMPATE\n";
        else if (dif1 < dif2) cout << a << '\n';
        else cout << c << '\n';
    }

    return 0;
}