#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (i % 2) cout << s << '\n';
    }

    return 0;
}