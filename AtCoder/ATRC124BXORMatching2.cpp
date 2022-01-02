#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    unordered_map<int, int> mp;
    unordered_map<int, unordered_set<int>> ms;
    int aux;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            aux = a[i] ^ b[j];
            if (ms[i].count(aux)) continue;
            ms[i].insert(aux);
            ++mp[aux];
        }
    }

    vector<int> sols;
    for (auto cv : mp) {
        if (cv.second == n) sols.push_back(cv.first);
    }
    sort(sols.begin(), sols.end());

    cout << sols.size() << '\n';
    for (int i = 0; i < sols.size(); ++i) cout << sols[i] << '\n';
    return 0;
}