#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'a') ++i;
    while (i < s.size()) {
        cout << s[i];
        ++i;
    }
    cout << '\n';

    return 0;
}