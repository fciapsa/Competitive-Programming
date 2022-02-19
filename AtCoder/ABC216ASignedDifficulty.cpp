#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x, y;
    char c;
    cin >> x >> c >> y;
    if (y <= 2) cout << x << "-\n";
    else if (y <= 6) cout << x << '\n';
    else cout << x << "+\n";

    return 0;
}