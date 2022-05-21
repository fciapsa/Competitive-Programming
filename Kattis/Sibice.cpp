#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    double w, h, mx, x;
    cin >> n >> w >> h;
    mx = sqrt(w * w + h * h);
    while (n--) {
        cin >> x;
        if (x <= mx) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}