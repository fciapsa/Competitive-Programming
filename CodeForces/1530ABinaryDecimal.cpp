#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, max, x;
    cin >> tc;
    while (tc--) {
        max = 1;
        cin >> n;
        while (n > 0) {
            x = n % 10;
            if (x > max) max = x;
            n /= 10;
        }

        cout << max << '\n';
    }

    return 0;
}