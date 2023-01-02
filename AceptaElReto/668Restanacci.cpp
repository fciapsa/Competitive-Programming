#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, n, act, prev, aux;
    cin >> a >> b >> n;
    while (a || b || n) {
        n %= 6;
        if (n == 0) cout << a;
        else if (n == 1)cout << b;
        else if (n == 2) cout << b - a;
        else if (n == 3) cout << -a;
        else if (n == 4) cout << -b;
        else cout << a - b;
        cout << '\n';
        cin >> a >> b >> n;
    }

    return 0;
}