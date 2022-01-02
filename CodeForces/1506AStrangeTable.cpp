#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc;
    ll n, m, x, i, j;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> x;
        if (x % n) i = x % n;
        else i = n;
        j = ceil((double)x / n);
        cout << (i-1) * m + j << '\n';
    }

return 0;
}