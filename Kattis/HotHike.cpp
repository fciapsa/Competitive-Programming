#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, best, mn;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)cin >> v[i];

    mn = max(v[0],v[2]);
    best = 1;
    for (int i = 1; i < n - 2; ++i) {
        if (max(v[i], v[i + 2]) < mn) {
            mn = max(v[i], v[i + 2]);
            best = i + 1;
        }
    }

    cout << best << ' ' << mn << '\n';

    return 0;
}