#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int t = 0, c = 0, g = 0;
    for (char cc : s) {
        if (cc == 'T')++t;
        else if (cc == 'C')++c;
        else ++g;
    }
    cout << t * t + c * c + g * g + min(t, min(c, g)) * 7 << '\n';
    return 0;
}