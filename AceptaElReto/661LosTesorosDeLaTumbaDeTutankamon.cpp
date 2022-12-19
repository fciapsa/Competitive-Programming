#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct obj {
    string name;
    int value, w, ind;
    bool operator<(obj const& o) const {
        return value > o.value || (value == o.value && w < o.w ||
            (value == o.value && w == o.w && ind < o.ind));
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        vector<obj> objs(n);
        for (int i = 0; i < n; ++i) {
            cin >> objs[i].name >> objs[i].value >> objs[i].w;
            objs[i].ind = i;
        }
        sort(objs.begin(), objs.end());
        cout << objs[0].name;
        for (int i = 1; i < n; ++i) cout << ' ' << objs[i].name;
        cout << '\n';

        cin >> n;
    }

    return 0;
}