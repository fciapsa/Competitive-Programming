#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v1(n), v2(n), pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
        pos[v1[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
        //reduce lcs to lis
        v2[i] = pos[v2[i]];
    }

    vector<int> d(n + 1, INF);//d[i] == lowest number in which an increasing seq of length i ends
    d[0] = -INF;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(d.begin(), d.end(), v2[i]) - d.begin();
        if (d[j - 1] < v2[i] && v2[i] < d[j]) d[j] = v2[i];
    }

    int lis = 0;
    for (int i = 1; i <= n; ++i) if (d[i] < INF) lis = i;

    cout << "2 " << lis + 1 << '\n';

return 0;
}