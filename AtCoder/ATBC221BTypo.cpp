#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    vector<int> diffs;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) diffs.push_back(i);
    }

    if (diffs.size() == 0) cout << "Yes\n";
    else if (diffs.size() == 2) {
        if (diffs[1] == diffs[0] + 1 && s[diffs[1]] == t[diffs[0]] && s[diffs[0]] == t[diffs[1]]) cout << "Yes\n";
        else cout << "No\n";
    }
    else cout << "No\n";

    return 0;
}