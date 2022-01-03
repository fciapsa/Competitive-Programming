#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, k, mx;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        if (n % 2) mx = n / 2 + 1;
        else mx = n / 2;

        if (k > mx) cout << -1 << '\n';
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (k && i % 2 == 0 && i == j) {
                        cout << 'R';
                        --k;
                    }
                    else cout << '.';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}