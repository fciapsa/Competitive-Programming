#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a, b, c;

int num(char cc) {
    if (cc == 'A') return a;
    else if (cc == 'B') return b;
    else return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    int x1, x2, x3;
    string s;
    cin >> x1 >> x2 >> x3;
    cin >> s;
    a = min(x1, min(x2, x3));
    c = max(x1, max(x2, x3));
    if (x1 != a && x1 != c) b = x1;
    else if (x2 != a && x2 != c) b = x2;
    else b = x3;

    cout << num(s[0]) << ' ' << num(s[1]) << ' ' << num(s[2]) << '\n';

    return 0;
}