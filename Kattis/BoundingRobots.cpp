#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int w, l, y, n, rx, ry, tx, ty;
    char x;
    cin >> w >> l;
    while (w != 0) {
        cin >> n;
        rx = ry = tx = ty = 0;
        while (n--) {
            cin >> x >> y;
            if (x == 'u') {
                rx = min(rx + y, l - 1);
                tx += y;
            }
            else if (x == 'd') {
                rx = max(rx - y, 0);
                tx -= y;
            }
            else if (x == 'r') {
                ry = min(ry + y, w - 1);
                ty += y;
            }
            else {
                ry = max(ry - y, 0);
                ty -= y;
            }
        }
        cout << "Robot thinks " << ty << ' ' << tx << '\n';
        cout << "Actually at " << ry << ' ' << rx << '\n';
        cout << '\n';

        cin >> w >> l;
    }

    return 0;
}