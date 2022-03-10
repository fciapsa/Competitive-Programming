#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, c, b, x;
    cin >> n >> c >> b;
    unordered_set<int> broken;
    for (int i = 0; i < b; ++i) {
        cin >> x;
        broken.insert(x-1);
    }

    string s(n, '0');

    if (c % 2) {
        s[0] = '1';
        --c;
    }

    for (int i = 1; i < n && c; ++i) {
        if (broken.count(i)) continue;

        if (s[i - 1] == '0') {
            s[i] = '1';
            c -= 2;
        }
    }

    cout << s << '\n';

    return 0;
}