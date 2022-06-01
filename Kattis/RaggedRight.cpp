#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    vector<int> v;
    string s;
    getline(cin, s);
    while (cin) {
        v.push_back(s.size());
        getline(cin, s);
    }

    int ans = 0, mx = 0;
    for (int i = 0; i < v.size(); ++i) if (v[i] > mx) mx = v[i];
    for (int i = 0; i < v.size() - 1; ++i) ans += (mx - v[i]) * (mx - v[i]);
    cout << ans << '\n';

    return 0;
}