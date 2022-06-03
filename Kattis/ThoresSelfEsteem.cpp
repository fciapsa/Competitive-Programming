#include <bits/stdc++.h>

using namespace std;
#define ll long long

int common(string s1, string s2) {
    int ret = 0;
    for (int i = 0; i < s1.size() && i < s2.size() && s1[i] == s2[i]; ++i) ++ret;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    string name = "ThoreHusfeldt";
    int n, longest_pref = 0;
    string s;

    cin >> n >> s;
    --n;

    if (s == name) cout << "Thore is awesome\n";
    else longest_pref = max(longest_pref, common(name, s));
    while (n--) {
        cin >> s;
        if (s == name) {
            if (longest_pref >= 12) cout << "Thore sucks\n";
            else {
                for (int i = 0; i <= longest_pref; ++i) cout << name[i];
                cout << '\n';
            }
        }
        else longest_pref = max(longest_pref, common(name, s));
    }

    return 0;
}