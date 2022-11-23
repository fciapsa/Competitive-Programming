#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, l, r, x, a, b;
    cin >> tc;
    while (tc--) {
        cin >> l >> r >> x >> a >> b;
        int best = 4;
        if (a == b) cout << "0\n";
        else if (b > a) {
            if (b - a >= x) best = 1;

            if (a - l >= x) {
                if (b - l >= x) best = min(best, 2);
                else if (r - l >= x && r - b >= x) best = min(best, 3);
            }

            if (r - a >= x) {
                if(r-b >= x) best = min(best, 2);
                else if (r - l >= x && b-l >= x) best = min(best, 3);
            }

            if (best == 4) cout << "-1\n";
            else cout << best << '\n';
        }
        else {//a > b
            if (a - b >= x) best = 1;
            
            if (a - l >= x) {
                if (b - l >= x) best = min(best, 2);
                else if (r - l >= x && r - b >= x) best = min(best, 3);
            }

            if (r - a >= x) {
                if (r - b >= x) best = min(best, 2);
                else if (r - l >= x && b - l >= x) best = min(best, 3);
            }

            if (best == 4) cout << "-1\n";
            else cout << best << '\n';
        }
    }

    return 0;
}