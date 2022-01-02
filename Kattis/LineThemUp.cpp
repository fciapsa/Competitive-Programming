#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n), inc, dec;
    for (int i = 0; i < n; ++i) cin >> v[i];
    inc = v;
    dec = v;

    sort(inc.begin(), inc.end());
    sort(dec.rbegin(), dec.rend());
    if (v == inc) cout << "INCREASING\n";
    else if (v == dec) cout << "DECREASING\n";
    else cout << "NEITHER\n";

    return 0;
}