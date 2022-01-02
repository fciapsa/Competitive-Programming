#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int r, e, c, n;
    cin >> n;
    while (n--) {
        cin >> r >> e >> c;
        if (r > e - c) cout << "do not advertise\n";
        else if (r == e - c)cout << "does not matter\n";
        else cout << "advertise\n";
    }
    return 0;
}