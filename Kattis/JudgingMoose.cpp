#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int l, r;
    cin >> l >> r;
    if (l == 0 && r == 0) cout << "Not a moose\n";
    else if (l == r) cout << "Even " << 2*l << '\n';
    else cout << "Odd " << max(l, r) * 2 << '\n';
    return 0;
}