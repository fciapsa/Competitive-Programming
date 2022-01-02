#include <bits/stdc++.h>

using namespace std;
#define ll long long

int c2i(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);
    string s1, s2;
    int a, b;
    cin >> s1 >> s2;
    a = c2i(s1[2]) * 100 + c2i(s1[1]) * 10 + c2i(s1[0]);
    b = c2i(s2[2]) * 100 + c2i(s2[1]) * 10 + c2i(s2[0]);
    cout << max(a, b) << '\n';
    return 0;
}