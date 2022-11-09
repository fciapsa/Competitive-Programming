#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n;
    ll x, pos, neg;
    cin >> tc;
    while (tc--) {
        cin >> n;
        pos = neg = 0;
        while (n--) {
            cin >> x;
            if (x >= 0) pos += x;
            else neg += x;
        }
        cout << max(pos + neg, -neg - pos) << '\n';
    }

    return 0;
}