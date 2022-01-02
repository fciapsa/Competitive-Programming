#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, c1, c2, c3, with0, with1, p1, p2, cont;
    bool z1, z2, z3, o1, o2, o3;
    string s1, s2, s3;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> s1 >> s2 >> s3;
        z1 = z2 = z3 = o1 = o2 = o3 = false;
        c1 = c2 = c3 = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (s1[i] == '0') ++c1;
            if (s2[i] == '0') ++c2;
            if (s3[i] == '0') ++c3;
        }
        
        with0 = with1 = 0;
        z1 = c1 >= n;
        if (z1) ++with0;
        o1 = c1 <= n;
        if (o1) ++with1;
        z2 = c2 >= n;
        if (z2) ++with0;
        o2 = c2 <= n;
        if (o2) ++with1;
        z3 = c3 >= n;
        if (z3) ++with0;
        o3 = c3 <= n;
        if (o3) ++with1;

        cont = 0;
        if (with0 >= 2) {
            if (z1) {
                if (!z2) s2 = s3;

            }
            else {
                s1 = s2;
                s2 = s3;
            }

            p1 = p2 = 0;
            while (p1 < 2*n && p2 < 2*n) {
                if (s1[p1] == s2[p2]) {
                    cout << s1[p1];
                    ++p1;
                    ++p2;
                }
                else if (s1[p1] == '1') {
                    cout << '1';
                    ++p1;
                }
                else {
                    cout << '1';
                    ++p2;
                }
                ++cont;
            }
            while (p1 < 2*n) {
                cout << s1[p1];
                ++p1;
                ++cont;
            }
            while (p2 < 2*n) {
                cout << s2[p2];
                ++p2;
                ++cont;
            }
            while (cont < 3 * n) {
                cout << '0';
                ++cont;
            }
        }
        else {
            if (o1) {
                if (!o2) s2 = s3;
            }
            else {
                s1 = s2;
                s2 = s3;
            }

            p1 = p2 = 0;
            while (p1 < 2*n && p2 < 2*n) {
                if (s1[p1] == s2[p2]) {
                    cout << s1[p1];
                    ++p1;
                    ++p2;
                }
                else if (s1[p1] == '0') {
                    cout << '0';
                    ++p1;
                }
                else {
                    cout << '0';
                    ++p2;
                }
                ++cont;
            }
            while (p1 < 2*n) {
                cout << s1[p1];
                ++p1;
                ++cont;
            }
            while (p2 < 2*n) {
                cout << s2[p2];
                ++p2;
                ++cont;
            }
            while (cont < 3 * n) {
                cout << '0';
                ++cont;
            }
        }
        cout << '\n';
    }
    return 0;
}