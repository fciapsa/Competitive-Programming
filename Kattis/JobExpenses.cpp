#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, sol = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x < 0) sol -= x;
    }
    cout << sol << '\n';
    return 0;
}