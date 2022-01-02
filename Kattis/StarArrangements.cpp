#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int s;
    cin >> s;
    cout << s << ":\n";
    for (int x = 2; x < s; ++x) {
        if (s % (2 * x - 1) == 0 || s % (2 * x - 1) == x) cout << x << ',' << x - 1 << '\n';
        if (s % x == 0) cout << x << ',' << x << '\n';
    }
    return 0;
}