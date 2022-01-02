#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int b = 0, w = 0;
    for (char c : s) {
        if (c == 'B') ++b;
        else ++w;
    }
    cout << (b == w) << '\n';
    return 0;
}