#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    int diff1 = v[1] - v[0], diff2 = v[2] - v[1];
    if (diff1 < diff2) cout << v[1] + diff1 << '\n';
    else if (diff2 < diff1) cout << v[0] + diff2 << '\n';
    else cout << v[2] + diff1 << '\n';

    return 0;
}