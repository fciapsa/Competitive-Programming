#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
    int x, y;
    bool operator<(par const& other) const {
        return x < other.x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<par> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x;
        v[i].y = i+1;
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-2].y << '\n';
    return 0;
}