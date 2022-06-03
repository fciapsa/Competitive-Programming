#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n1, n2, t, pos;
    string s1, s2;
    cin >> n1 >> n2 >> s1 >> s2 >> t;

    vector<char> ans(n1 + n2);
    for (int i = 0; i < n1; ++i) {
        pos = min(n1 - 1 - i + t - min(t,i), n1 + n2 - 1 - i);
        ans[pos] = s1[i];
    }
    for (int i = n1, j = 0; j < n2; ++i,++j) {
        pos = max(n1 + j - t + min(t,j), j);
        ans[pos] = s2[j];
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i];
    cout << '\n';

    return 0;
}