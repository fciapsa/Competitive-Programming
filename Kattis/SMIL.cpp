#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size() - 1; ++i) {
        if ((s[i] == ':' || s[i] == ';') && s[i + 1] == ')') cout << i << '\n';
    }
    for (int i = 0; i < s.size() - 2; ++i) {
        if ((s[i] == ':' || s[i] == ';') && s[i + 1] == '-' && s[i+2]==')') cout << i << '\n';
    }
    return 0;
}