#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int g, t, n, sum, x;
    cin >> g >> t >> n;
    sum = 0;
    while (n--) {
        cin >> x;
        sum += x;
    }
    cout << ((g - t) / 10) * 9 - sum << '\n';

    return 0;
}