#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x;
    bool first;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> vodd, veven;
        first = true;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 2) vodd.push_back(x);
            else veven.push_back(x);
        }

        for (int i = 0; i < vodd.size(); ++i) {
            if (first) {
                first = false;
                cout << vodd[i];
            }
            else cout << ' ' << vodd[i];
        }
        for (int i = 0; i < veven.size(); ++i) {
            if (first) {
                first = false;
                cout << veven[i];
            }
            else cout << ' ' << veven[i];
        }
        cout << '\n';
    }

return 0;
}