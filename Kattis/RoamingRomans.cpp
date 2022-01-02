#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double m;
    cin >> m;
    cout << (int)((1000.0 * 5280.0 / 4854) * m + 0.5) << '\n';
    return 0;
}