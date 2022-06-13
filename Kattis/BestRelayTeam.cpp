#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct runner {
    string name;
    double a, b;
};

struct ordA {
    bool operator()(runner const& r1, runner const& r2) {
        return r1.a < r2.a;
    }
};

struct ordB {
    bool operator()(runner const& r1, runner const& r2) {
        return r1.b < r2.b;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<runner> v1(n), v2;
    for (int i = 0; i < n; ++i) cin >> v1[i].name >> v1[i].a >> v1[i].b;
    v2 = v1;
    sort(v1.begin(), v1.end(), ordA());
    sort(v2.begin(), v2.end(), ordB());

    vector<vector<runner>> sols(4);
    vector<double> times(4);
    for (int i = 0; i < 4; ++i) {
        sols[i].push_back(v1[i]);
        times[i] = v1[i].a;
    }

    double best = 1e9;
    int best_ind = -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; sols[i].size() < 4; ++j) {
            if (v2[j].name != sols[i][0].name) {
                sols[i].push_back(v2[j]);
                times[i] += v2[j].b;
            }
        }
        if (times[i] < best) {
            best = times[i];
            best_ind = i;
        }
    }

    cout << fixed << setprecision(9) << times[best_ind] << '\n';
    for (int i = 0; i < 4; ++i) cout << sols[best_ind][i].name << '\n';

    return 0;
}