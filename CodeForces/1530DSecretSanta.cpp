#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

struct pers {
    int x;
    vector<int> v;
};

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, k, a, ind, assign;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<bool> recibe(n + 1, false);
        vector<pers> vp(n + 1);
        vector<int> b(n + 1);
        k = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            ++vp[a].x;
            vp[a].v.push_back(i);
        }
        
        for (int i = 1; i <= n; ++i) {
            if (vp[i].x == 1) {
                recibe[i] = true;
                b[vp[i].v[0]] = i;
                ++k;
            }
        }

        for (int i = 1; i <= n; ++i) {
           if (vp[i].x > 1 && k < n - 2) {
                bool stop = false;
                for (int j = 0; j < vp[i].v.size() && !stop; ++j) {
                    if (b[vp[i].v[j]] == 0) {
                        stop = true;
                        recibe[i] = true;
                        b[vp[i].v[j]] = i;
                        ++k;
                    }
                }
            }
        }

        ind = 1;
        assign = k;
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0 && assign < n-2) {
                while (ind <= n && (recibe[ind] || ind == i)) ++ind;
                if (ind <= n) {
                    b[i] = ind;
                    recibe[ind] = true;
                    ++assign;
                }
            }
        }

        ind = 1;
        while (assign < n) {
            if (b[ind] == 0) {
                if (assign < n - 2) {
                    bool done = false;
                    for (int i = 1; i <= n && !done; ++i) {
                        if (i != ind && !recibe[i]) {
                            b[ind] = i;
                            recibe[i] = true;
                            done = true;
                            ++assign;

                            bool found = false;
                            for (int p = 0; p < vp[i].v.size() && !found; ++p) {
                                found = vp[i].v[p] == ind;
                            }
                            if (found) ++k;
                        }
                    }
                }
                else if (assign == n - 2) {
                    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
                    for (int j = 1; j <= n; ++j) {
                        if (b[j] == 0) {
                            if (x1 == 0) x1 = j;
                            else x2 = j;
                        }
                        if (!recibe[j]) {
                            if (y1 == 0) y1 = j;
                            else y2 = j;
                        }
                    }

                    if (x1 == y1 || x2 == y2) {
                        b[x1] = y2;
                        bool found = false;
                        for (int p = 0; p < vp[y2].v.size() && !found; ++p) {
                            found = vp[y2].v[p] == x1;
                        }
                        if (found) ++k;
                        b[x2] = y1;
                        found = false;
                        for (int p = 0; p < vp[y1].v.size() && !found; ++p) {
                            found = vp[y1].v[p] == x2;
                        }
                        if (found) ++k;
                    }
                    else {
                        b[x1] = y1;
                        bool found = false;
                        for (int p = 0; p < vp[y1].v.size() && !found; ++p) {
                            found = vp[y1].v[p] == x1;
                        }
                        if (found) ++k;
                        b[x2] = y2;
                        found = false;
                        for (int p = 0; p < vp[y2].v.size() && !found; ++p) {
                            found = vp[y2].v[p] == x2;
                        }
                        if (found) ++k;
                    }
                    assign += 2;
                }
                else {
                    bool stop = false;
                    for (int j = 1; j <= n && !stop; ++j) {
                        if (!recibe[j]) {
                            b[ind] = j;
                            stop = true;
                            ++assign;
                            bool found = false;
                            for (int p = 0; p < vp[j].v.size() && !found; ++p) {
                                found = vp[j].v[p] == ind;
                            }
                            if (found) ++k;
                        }
                    }
                }
            }
            ++ind;
        }

        cout << k << '\n';
        cout << b[1];
        for (int i = 2; i <= n; ++i) cout << ' ' << b[i];
        cout << '\n';
    }

    return 0;
}