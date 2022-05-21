#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int p, n;
    cin >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> n >> n;
        cout << i << ' ' << n + (n * (n + 1)) / 2 << '\n';
    }

    return 0;
}