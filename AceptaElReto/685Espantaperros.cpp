#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    while (x1 | y1 | x2 | y2) {
        if (x1 == x2 || y1 == y2 || x1-x2 == y1-y2 || x1-x2 == y2-y1) cout << "SI\n";
        else cout << "NO\n";

        cin >> x1 >> y1 >> x2 >> y2;
    }

    return 0;
}