#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, s1, s2, s3, s4;
    cin >> tc;
    while (tc--) {
        cin >> s1 >> s2 >> s3 >> s4;
        if (s1 > s2) {//s1 win
            if (s3 > s4) {//s3 win
                if (s2 > s3 || s4 > s1) cout << "NO\n";
                else cout << "YES\n";
            }
            else {//s4 win
                if (s2 > s4 || s3 > s1) cout << "NO\n";
                else cout << "YES\n";
            }
        }
        else {//s2 win
            if (s3 > s4) {//s3 win
                if (s1 > s3 || s4 > s2) cout << "NO\n";
                else cout << "YES\n";
            }
            else {//s4 win
                if (s1 > s4 || s3 > s2) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }

return 0;
}