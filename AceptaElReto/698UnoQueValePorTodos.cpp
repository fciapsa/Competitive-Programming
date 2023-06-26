#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, mx, act;
    ll sum;
    cin >> tc;
    while (tc--) {
        cin >> n >> mx;
        sum = 0;
        for (int i = 1; i < n * n; ++i) {
            cin >> act;
            if (act > mx) {
                sum += mx;
                mx = act;
            }
            else sum += act;
        }
        if (sum == mx) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}