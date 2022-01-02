#include <bits/stdc++.h>

using namespace std;
#define ll long long

int clen(int n) {
    if (n == 1) return 1;
    
    if (n % 2) return 1 + clen(3 * n + 1);
    else return 1 + clen(n / 2);
}

int main() {
    std::ios::sync_with_stdio(false);

    int i, j, mx;
    cin >> i >> j;
    while (cin) {
        mx = 0;
        for (int x = min(i,j); x <= max(i,j); ++x) mx = max(mx, clen(x));
        cout << i << ' ' << j << ' ' << mx << '\n';
        cin >> i >> j;
    }

    return 0;
}