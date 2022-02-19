#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int q = a / c;
    if (c * q >= a && c * q <= b) cout << c * q << '\n';
    else if (c * (q + 1) >= a && c * (q + 1) <= b) cout << c * (q + 1) << '\n';
    else cout << "-1\n";
         
    return 0;
}