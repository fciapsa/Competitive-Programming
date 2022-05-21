#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.size(); ++i) if (s[i] != s[i - 1]) cout << s[i];
    cout << '\n';

    return 0;
}