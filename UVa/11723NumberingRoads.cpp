#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, r, k = 1;
    cin >> r >> n;
    while (r!=0) {
        cout << "Case " << k++ << ": ";
        if (r > 27 * n) cout << "impossible\n";
        else {
            if (r % n) cout << r / n << '\n';
            else cout << r / n - 1 << '\n';
        }
        cin >> r >> n;
    }
    return 0;
}