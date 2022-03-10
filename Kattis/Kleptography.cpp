#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string a(m, ' '), b;
    for (int i = m - n; i < m; ++i) cin >> a[i];
    cin >> b;
    for (int i = m - n - 1; i >= 0; --i) {
        if (b[i + n] < a[i + n]) a[i] = char(b[i + n] + 26 - a[i + n] + 'a');
        else a[i] = char(b[i + n] - a[i + n]+ 'a');
    }
    cout << a << '\n';

    return 0;
}