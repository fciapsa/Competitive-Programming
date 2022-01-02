#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

struct par {
    int ind, val;
};

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, next, chgInd;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        vector<bool> used(n + 1, false);
        vector<par> chgs;
        chgs.push_back({ 0,v[0] });
        used[v[0]] = true;
        for (int i = 1; i < n; ++i) if (v[i] != v[i - 1]) {
            chgs.push_back({ i, v[i] });
            used[v[i]] = true;
        }

        next = 1;
        chgInd = 0;
        vector<int> sol1(n);
        for (int i = 0; i < chgs.size(); ++i) sol1[chgs[i].ind] = chgs[i].val;
        for (int i = 0; i < n; ++i) {
            if (sol1[i] == 0) {
                while (used[next]) ++next;
                used[next] = true;
                sol1[i] = next;
            }
        }
        cout << sol1[0];
        for (int i = 1; i < n; ++i) cout << ' ' << sol1[i];
        cout << '\n';

        vector<int> sol2(n);
        vector<bool> used2(n + 1, false);
        for (int i = 0; i < chgs.size(); ++i) {
            used2[chgs[i].val] = true;
            sol2[chgs[i].ind] = chgs[i].val;
        }
        priority_queue<int> pq;
        next = 1;
        while (next <= sol2[0]) {
            if (!used2[next]) pq.push(next);
            ++next;
        }
        for (int i = 0; i < n; ++i) {
            if(sol2[i] == 0){
                sol2[i] = pq.top();
                pq.pop();
            }
            else {
                while (next <= sol2[i]) {
                    if (!used2[next]) pq.push(next);
                    ++next;
                }
            }
        }
        cout << sol2[0];
        for (int i = 1; i < n; ++i)cout << ' ' << sol2[i];
        cout << '\n';
    }

    return 0;
}