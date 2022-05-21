#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) if (isupper(s[i])) cout << s[i];
    cout << '\n';

    return 0;
}