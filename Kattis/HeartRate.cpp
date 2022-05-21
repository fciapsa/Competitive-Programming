#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double b, p;
    int n;
    cin >> n;
    while (n--) {
        cin >> b >> p;
        cout << fixed << setprecision(4) << (60.0 * (b - 1)) / p << ' ' << (60.0 * b) / p << ' ' << (60.0 * (b + 1)) / p << '\n';
    }

    return 0;
}