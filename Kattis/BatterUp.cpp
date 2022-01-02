#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, q = 0, p = 0, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x >= 0) {
            p += x;
            ++q;
        }
    }
    cout << (double)p / q << '\n';
    return 0;
}