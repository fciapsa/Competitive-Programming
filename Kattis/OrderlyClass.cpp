#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    int i1 = -1, i2= -1;//first and last difference
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            if (i1 == -1) i2 = i1 = i;
            else i2 = i;
        }
    }

    bool ok = true;
    for (int i = i1, j = i2; i <= i2 && ok; ++i, --j) ok = s1[i] == s2[j];

    if (!ok) cout << "0\n";
    else {
        int ans = 1;
        for (int i = i1 - 1, j = i2 + 1; i >= 0 && j < s1.size() && s1[i] == s1[j]; --i, ++j) ++ans;
        cout << ans << '\n';
    }

    return 0;
}