#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    ll n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        n /= 10;
        n *= (n+1);
        if (n) cout << n;
        cout << 25 << '\n';
    }
    return 0;
}