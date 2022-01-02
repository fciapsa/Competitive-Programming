#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
    int k, n;
    vector<int> v(2);
    v[0] = 1;
    v[1] = 1;
    int x;
    for (int i = 2; i <= 30; ++i) {
        x = v[v.size() - 1] + 2 * v[v.size() - 2];
        v.push_back(x);
    }
    for (int i = 1; i <= 30; ++i) {
        v[i] += v[i - 1];
    }
    cin >> k;
    while (k--) {
        cin >> n;
        int sol = 0;
        while (v[sol] < n) ++sol;
        cout << sol+1 << '\n';
    }
return 0;
}