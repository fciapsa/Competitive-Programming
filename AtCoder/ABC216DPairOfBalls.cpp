#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct nmb {
    int veces, m1, m2;
};

struct mont {
    vector<int> colores;
    int ind;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k, a;
    cin >> n >> m;
    vector<nmb> nums(n + 1);
    vector<mont> monts(m);

    queue<nmb> q;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        cin >> a;
        monts[i].colores.push_back(a);
        ++nums[a].veces;
        if (nums[a].veces == 1) nums[a].m1 = i;
        else {
            nums[a].m2 = i;
            q.push(nums[a]);
        }
        for (int j = 1; j < k; ++j) {
            cin >> a;
            monts[i].colores.push_back(a);
        }
    }

    int elim = 0, ind;
    nmb act;
    while (!q.empty()) {
        act = q.front();
        q.pop();
        ++elim;

        ind = ++monts[act.m1].ind;
        if (ind < monts[act.m1].colores.size()) {
            a = monts[act.m1].colores[ind];
            ++nums[a].veces;
            if (nums[a].veces == 1) nums[a].m1 = act.m1;
            else {
                nums[a].m2 = act.m1;
                q.push(nums[a]);
            }
        }

        ind = ++monts[act.m2].ind;
        if (ind < monts[act.m2].colores.size()) {
            a = monts[act.m2].colores[ind];
            ++nums[a].veces;
            if (nums[a].veces == 1) nums[a].m1 = act.m2;
            else {
                nums[a].m2 = act.m2;
                q.push(nums[a]);
            }
        }
    }

    if (elim == n) cout << "Yes\n";
    else cout << "No\n";

return 0;
}