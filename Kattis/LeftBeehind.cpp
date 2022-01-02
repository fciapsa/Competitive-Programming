#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    while (x || y) {
        if (x + y == 13) cout << "Never speak again.\n";
        else if(x == y)cout << "Undecided.\n";
        else if(x>y)cout << "To the convention.\n";
        else cout << "Left beehind.\n";
        cin >> x >> y;
    }
    return 0;
}