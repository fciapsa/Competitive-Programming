#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n % 2) {
            cout << '1';
            for (int i = 1; i < n; ++i) cout << " 1";
        }
        else {
            cout << "1 3";
            for (int i = 2; i < n; ++i) cout << " 2";
        }
        cout << '\n';
    }

    return 0;
}