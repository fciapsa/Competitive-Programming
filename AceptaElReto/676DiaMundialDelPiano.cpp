#include <bits/stdc++.h>

using namespace std;
#define ll long long

int bisUntil(int year) {
    return year / 4 - year / 100 + (year/400);
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, y1, y2, bis1, bis2, len, bisTotal;
    cin >> tc;
    while (tc--) {
        cin >> y1 >> y2;
        bis1 = bisUntil(y1 - 1);
        bis2 = bisUntil(y2);
        len = y2 - y1 + 1;
        bisTotal = bis2 - bis1;
        cout << len - bisTotal << ' ' << bisTotal << '\n';
    }

    return 0;
}