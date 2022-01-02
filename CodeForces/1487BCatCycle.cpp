#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, k, skips;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        if (n % 2 == 0) {
            if (k % n == 0) cout << n << '\n';
            else cout << k % n << '\n';
        }
        else {
            if (k <= n / 2) cout << k << '\n';
            else {
                skips = (k - n / 2 - 1) / (n / 2) + 1;
                k += skips;
                if (k % n == 0) cout << n << '\n';
                else cout << k % n << '\n';
            }
        }
    }

    return 0;
}