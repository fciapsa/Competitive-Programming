#include <iostream>
#include <vector>
#include <string>

/* Total points are 3n(n-1) / 2 
If n is odd it can be achieved without ties. If n is even, total points aren't divisible by n. Each tie reduces
the total sum by 1, and since (3n(n-1) / 2 mod n) = n/2 we need n/2 ties to obtain a multiple of n total sum(this is
optimal amount of ties).

To determine which matches to win and which one to lose, we place the teams in a circle and do the following for the
i-th team:
    -If n is odd, win against the next floor(n/2) teams and lose against all the others
    -If n is even, win against the next (n-2)/2 teams, lose against the previous (n-2)/2 teams and tie with the
    opposite team(the (i + n/2) mod n).
*/

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<vector<int>> results(n, vector<int>(n,-1));
        if (n % 2) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1, k = 0; k < n / 2; ++j, ++k) {
                    j %= n;
                    results[i][j] = 1;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                results[i][(i + n / 2) % n] = 0;
                for (int j = i + 1, k = 0; k < (n - 2) / 2; ++j, ++k) {
                    j %= n;
                    results[i][j] = 1;
                }
            }
        }

        cout << results[0][1];
        for (int j = 2; j < n; ++j) cout << ' ' << results[0][j];
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cout << ' ' << results[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}