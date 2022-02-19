#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int k, p = 1;
    cin >> s >> k;
    vector<char> v(s.size());
    for (int i = 0; i < s.size(); ++i) v[i] = s[i];
    sort(v.begin(), v.end());
    while (p < k) {
        next_permutation(v.begin(), v.end());
        ++p;
    }
    for (int i = 0; i < v.size(); ++i)cout << v[i];
    cout << '\n';
    return 0;
}