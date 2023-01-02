#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, tam, ans, mx, x;
    cin >> n;
    while (n) {
        ans = 1000;
        for (int i = 0; i < n; ++i) {
            mx = 0;
            cin >> tam;
            for (int j = 0; j < tam; ++j) {
                cin >> x;
                if (x > mx) mx = x;
            }
            ans = min(ans, mx);
        }
        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}