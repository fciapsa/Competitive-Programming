#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x, x1, xmin;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> x1;
        xmin = x1;
        --n;
        while (n--) {
            cin >> x;
            if (x < xmin) xmin = x;
        }

        if (x1 == xmin) cout << "Bob\n";
        else cout << "Alice\n";
    }

    return 0;
}