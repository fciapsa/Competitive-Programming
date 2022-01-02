#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x, c1, c2, c0, obj, sol, need, have;
    cin >> tc;
    while (tc--) {
        cin >> n;
        c0 = 0;
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 3 == 0) ++c0;
            else if (x % 3 == 1) ++c1;
            else ++c2;
        }
        obj = (c0 + c1 + c2) / 3;
        sol = 0;
        if (c0 < obj) {
            need = obj - c0;
            if (c2 > obj) {
                have = c2 - obj;
                if (have >= need) {
                    sol += need;
                    need = 0;
                    c2 -= need;
                }
                else {
                    sol += have;
                    need -= have;
                    c2 -= have;
                }
            }

            if (need > 0) {
                c1 -= need;
                sol += 2 * need;
            }
        }
        if (c1 < obj) {
            need = obj - c1;
            if (c0 > obj) {
                have = c0 - obj;
                if (have >= need) {
                    sol += need;
                    need = 0;
                    c0 -= need;
                }
                else {
                    sol += have;
                    need -= have;
                    c0 -= have;
                }
            }

            if (need > 0) {
                c2 -= need;
                sol += 2 * need;
            }
        }

        if (c2 < obj) {
            need = obj - c2;
            if (c1 > obj) {
                have = c1 - obj;
                if (have >= need) {
                    sol += need;
                    need = 0;
                    c1 -= need;
                }
                else {
                    sol += have;
                    need -= have;
                    c1 -= have;
                }
            }

            if (need > 0) {
                c0 -= need;
                sol += 2 * need;
            }
        }
        cout << sol << '\n';
    }

    return 0;
}