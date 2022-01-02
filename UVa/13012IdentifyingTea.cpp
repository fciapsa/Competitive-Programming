#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int t, sol, x;
    cin >> t;
    while (cin) {
        sol = 0;
        for (int i = 0; i < 5; ++i) {
            cin >> x;
            if (x == t) ++sol;
        }
        cout << sol << '\n';
        cin >> t;
    }
    return 0;
}