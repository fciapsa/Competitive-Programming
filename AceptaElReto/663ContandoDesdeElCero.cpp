#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, x;
    cin >> tc;
    while (tc--) {
        cin >> x;
        if (x >= 0) cout << x - 1 << '\n';
        else cout << x << '\n';
    }

    return 0;
}