#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, dif, x1, x2;
    cin >> a >> b;
    dif = b - a;
    int gcd = dif;
    for (; gcd > 0; --gcd) {
        x1 = floor((double)b / gcd);
        x2 = ceil((double)a / gcd);
        if (x1 != x2) break;
    }
    cout << gcd << '\n';
    return 0;
}