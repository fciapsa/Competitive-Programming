#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n % 2) cout << n << " is odd\n";
        else cout << n << " is even\n";
    }
    return 0;
}