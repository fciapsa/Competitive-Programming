#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s.size() % 2 || s[s.size() / 2] != ')') cout << "fix\n";
    else cout << "correct\n";
    return 0;
}