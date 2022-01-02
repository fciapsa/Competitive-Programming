#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double x, y;
    cin >> x >> y;
    if (x == 0) {
        if (y == 1) cout << "ALL GOOD\n";
        else cout << "0\n";
    }
    else {
        if (y == 1) cout << "IMPOSSIBLE\n";
        else cout << fixed << setprecision(6) << x / (1-y) << '\n';//without setprecision it gives WA
    }
    return 0;
}