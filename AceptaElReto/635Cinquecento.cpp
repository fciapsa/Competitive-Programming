#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x % 100 == 0) cout << x / 100 << '\n';
        else cout << x / 100 + 1 << '\n';
    }

    return 0;
}