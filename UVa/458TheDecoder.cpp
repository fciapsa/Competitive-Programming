#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    while (cin) {
        for (int i = 0; i < s.size(); ++i) s[i] = char(int(s[i]) - 7);
        cout << s << '\n';
        getline(cin, s);
    }

    return 0;
}