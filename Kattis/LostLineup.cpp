#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct ii {
    int id, pos;
    bool operator<(ii const& other)const {
        return pos < other.pos;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ii> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i].pos;
        v[i].id = i+2;
    }
    sort(v.begin(), v.end());
    cout << "1";
    for (int i = 0; i < n - 1; ++i) cout << ' ' << v[i].id;
    cout << '\n';
    return 0;
}