#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x, sol;
    cin >> tc;
    while (tc--) {
        cin >> n;
        sol = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x != 2) ++sol;
        }
        cout << sol << '\n';
    }

return 0;
}