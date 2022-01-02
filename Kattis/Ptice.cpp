#include <bits/stdc++.h>

using namespace std;
#define ll long long

const string adrian = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABC";
const string bruno = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";
const string goran = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABB";

int main() {
    std::ios::sync_with_stdio(false);
    int n, a = 0, b = 0, g = 0, ans;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == adrian[i])++a;
        if (s[i] == bruno[i])++b;
        if (s[i] == goran[i])++g;
    }

    ans = max(a, max(b, g));
    cout << ans << '\n';
    if (a == ans) cout << "Adrian\n";
    if (b == ans) cout << "Bruno\n";
    if (g == ans) cout << "Goran\n";

    return 0;
}