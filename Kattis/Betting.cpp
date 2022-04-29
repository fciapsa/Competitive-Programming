#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double a;
    cin >> a;
    a /= 100;
    cout << fixed << setprecision(4) << 1 / a << '\n' << 1 / (1 - a) << '\n';

    return 0;
}