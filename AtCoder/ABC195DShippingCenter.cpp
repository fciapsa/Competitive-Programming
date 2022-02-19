#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

struct obj {
    int w, v;
    bool operator<(obj const& other) const {
        return v > other.v || (v == other.v && w > other.w);
    }
};

struct box {
    int id, cap;
    bool operator<(box const& other) const {
        return cap < other.cap;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, q, L, R, sol;
    cin >> n >>  m >> q;
    vector<obj> objs(n);
    for (int i = 0; i < n; ++i) cin >> objs[i].w >> objs[i].v;
    sort(objs.begin(), objs.end());

    vector<box> boxes(m);
    for (int i = 1; i <= m; ++i) {
        boxes[i-1].id = i;
        cin >> boxes[i-1].cap;
    }
    sort(boxes.begin(), boxes.end());

    for (int p = 0; p < q; ++p) {
        cin >> L >> R;
        sol = 0;
        vector<bool> used(n, false);
        for (int i = 0; i < m; ++i) {
            if (boxes[i].id >= L && boxes[i].id <= R) continue;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && objs[j].w <= boxes[i].cap) {
                    used[j] = true;
                    sol += objs[j].v;
                    break;
                }
            }
        }

        cout << sol << '\n';
    }
    return 0;
}