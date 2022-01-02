#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, s, d, a, b;
    cin >> tc;
    while (tc--) {
        cin >> s >> d;
        if (s % 2) {//sumpa impar
            if (d % 2) {
                a = s / 2 + d / 2 + 1;
                b = s / 2 - d / 2;
                if (a >= 0 && b >= 0) cout << a << ' ' << b << '\n';
                else cout << "impossible\n";
            }
            else cout << "impossible\n";
        }
        else {//suma par
            if (d % 2) cout << "impossible\n";
            else {
                a = s / 2 + d / 2;
                b = s / 2 - d / 2;
                if (a >= 0 && b >= 0) cout << a << ' ' << b << '\n';
                else cout << "impossible\n";
            }
        }
    }
    return 0;
}