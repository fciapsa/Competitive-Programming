#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

//Simply print 1 k-3 times and reuse the solution for k=3 applied to n-k+3

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, k;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        while (k > 3) {
            cout << "1 ";
            --k;
            --n;
        }

        if (n % 2) cout << n / 2 << ' ' << n / 2 << " 1\n";
        else {
            if (n % 4) cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << '\n';
            else cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
        }
    }

    return 0;
}