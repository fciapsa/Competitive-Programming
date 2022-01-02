#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool win(int a, int b) {
    if (a >= 11 && a - b >= 2) return true;
    if (b >= 11 && b - a >= 2) return true;
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int a = 0, b = 0;
    char p, s;
    while (!win(a, b)) {
        cin >> p >> s;
        if (p == 'A') a += int(s) - int('0');
        else b += int(s) - int('0');
    }
    if (a > b) cout << "A\n";
    else cout << "B\n";
    return 0;
}