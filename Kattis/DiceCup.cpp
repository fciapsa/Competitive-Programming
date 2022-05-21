#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, mx;
    cin >> n >> m;
    vector<int> count(n + m + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ++count[i + j];
        }
    }

    mx = 0;
    for (int i = 2; i < count.size(); ++i) if (count[i] > mx) mx = count[i];
    for (int i = 2; i < count.size(); ++i) if (count[i] == mx) cout << i << '\n';

    return 0;
}