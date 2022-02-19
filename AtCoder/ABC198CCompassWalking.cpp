#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double r, x, y;
    cin >> r >> x >> y;
    double dist = hypot(x, y);
    if (dist >= r) cout << (ll)ceil(dist / r) << '\n';
    else cout << 2 << '\n';

    return 0;
}