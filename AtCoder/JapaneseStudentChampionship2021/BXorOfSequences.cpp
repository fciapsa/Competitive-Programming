#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++mp[x];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x;
        ++mp[x];
    }

    bool first = true;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second < 2) {
            if (first) {
                first = false;
                cout << it->first;
            }
            else cout << ' ' << it->first;
        }
    }

    return 0;
}