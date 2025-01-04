#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    ll ans;
    cin >> n;
    while (n) {
        vector<int> v(n);
        map<int, int> mpi, mpf;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (mpi.count(v[i]) == 0) {
                mpi[v[i]] = i;
                mpf[v[i]] = i;
            }
            else mpf[v[i]] = i;
        }

        ans = 0;
        for (auto it = mpi.begin(); it != mpi.end(); ++it) {
            ans += mpf[it->first] - it->second;
        }
        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}