#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct team {
    int a, b;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, p, t;
    cin >> n >> m;

    unordered_set<int> s;
    vector<team> v(n + 1);
    while (m--) {
        cin >> t >> p;
        ++v[t].a;
        v[t].b += p;
        if (t == 1) {
            vector<int> dels;
            for (int x: s) {
                if (v[x].a < v[1].a || (v[x].a == v[1].a && v[x].b >= v[1].b)) dels.push_back(x);
            }
            for (int x : dels) s.erase(x);
        }
        else if (v[t].a > v[1].a || (v[t].a == v[1].a && v[t].b < v[1].b)) s.insert(t);
        cout << s.size() + 1 << '\n';
    }

    return 0;
}