#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x, y, z;
    cin >> x >> y >> z;

    z *= y;
    if (z % x) cout << z / x << '\n';
    else cout << z / x - 1 << '\n';

    return 0;
}