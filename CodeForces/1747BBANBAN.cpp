#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, until;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << (n + 1) / 2 << '\n';

        if (n % 2) until = (3 * (n + 1)) / 2;
        else until = (3 * n) / 2;
        for (int i = 1, j = 3*n - 1; i <= until; i += 3, j -= 3) {
            cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}