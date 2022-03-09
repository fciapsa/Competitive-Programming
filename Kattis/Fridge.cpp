#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<pair<int, int>> v(10);
    for (int i = 0; i < 10; ++i) v[i] = { 0,i };
    for (int i = 0; i < s.size(); ++i) ++v[int(s[i]) - int('0')].first;

    sort(v.begin(), v.end());
    string sol = "";
    if (v[0].second == 0) {
        sol += char(v[1].second + '0');
        --v[1].first;
    }
    else {
        sol += char(v[0].second + '0');
        --v[0].first;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= v[0].first; ++i) sol.push_back(char(v[0].second + '0'));
    cout << sol << '\n';

    return 0;
}