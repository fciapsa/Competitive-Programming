#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    if (s == p) cout << "Yes\n";
    else if (isdigit(s[0]) && p.size() == s.size() - 1 && s.substr(1, s.size()-1) == p) cout << "Yes\n";
    else if (isdigit(s[s.size()-1]) && p.size() == s.size() - 1 && s.substr(0, s.size()-1) == p) cout << "Yes\n";
    else {
        for (int i = 0; i < p.size(); ++i) {
            if (isalpha(p[i])) {
                if (isupper(p[i])) p[i] = tolower(p[i]);
                else p[i] = toupper(p[i]);
            }
        }
        if (p == s) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}