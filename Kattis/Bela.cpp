#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<char, int> dom = { {'A',11},{'K',4}, {'Q',3},{'J',20}, {'T',10},{'9',14},{'8',0},{'7',0} };
map<char, int> notdom = { {'A',11},{'K',4}, {'Q',3},{'J',2}, {'T',10},{'9',0},{'8',0},{'7',0} };

int main() {
    std::ios::sync_with_stdio(false);
    int n, ans = 0;
    char c1, c2, b;
    cin >> n >> b;
    n *= 4;
    for (int i = 0; i < n; ++i) {
        cin >> c1 >> c2;
        if (c2 == b) ans += dom[c1];
        else ans += notdom[c1];
    }

    cout << ans << '\n';

    return 0;
}