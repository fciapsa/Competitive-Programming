#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, max;
    cin >> tc;
    string a, b;
    while (tc--) {
        cin >> a >> b;
        vector<vector<int>> lcsuff(a.size(), vector<int>(b.size()));
        for (int j = 0; j < b.size(); ++j) {
            if (a[0] == b[j]) lcsuff[0][j] = 1;
        }
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[0]) lcsuff[i][0] = 1;
        }

        for (int i = 1; i < a.size(); ++i) {
            for (int j = 1; j < b.size(); ++j) {
                if (a[i] == b[j]) lcsuff[i][j] = lcsuff[i - 1][j - 1] + 1;
            }
        }

        max = 0;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if (lcsuff[i][j] > max) max = lcsuff[i][j];
            }
        }

        cout << a.size() - max + b.size() - max << '\n';
    }

return 0;
}