#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, p;
    cin >> tc;
    while (tc--) {
        cin >> n >> p;
        vector<int> v1(n), v2;//v1 is the original, v2 has the digits ordered
        for (int i = 0; i < n; ++i) cin >> v1[i];
        v2 = v1;
        sort(v2.begin(), v2.end());

        int lowest_missing = 0, ind = 0;
        while (ind < v2.size() && lowest_missing >= v2[ind]) {
            if (lowest_missing == v2[ind]) ++lowest_missing;
            ++ind;
        }

        int greatest_missing = p - 1;
        ind = v2.size() - 1;
        while (ind >= 0 && greatest_missing <= v2[ind]) {
            if (greatest_missing == v2[ind]) --greatest_missing;
            --ind;
        }

        if (lowest_missing == p) cout << "0\n";
        else if (lowest_missing > v1[n - 1]) cout << greatest_missing - v1[n - 1] << '\n';
        else {
            int ans = p - v1[n - 1];
            //include the digits added until overflowing last digit(inclusive)
            //for (int i = v1[n - 1] + 1; i < p; ++i) v2.push_back(i); this is too slow xd, I do not need it
            v2.push_back(0);
            int indx = n - 2;
            while (indx >= 0 && v1[indx] == p - 1) --indx;
            if (indx < 0) v2.push_back(1);
            else v2.push_back(v1[indx] + 1);
                
            sort(v2.begin(), v2.end());

            lowest_missing = 0, ind = 0;
            while (ind < v2.size() && lowest_missing >= v2[ind]) {
                if (lowest_missing == v2[ind]) ++lowest_missing;
                ++ind;
            }

            greatest_missing = v1[n-1] - 1, ind = v2.size() - 1;
            while (ind >= 0 && greatest_missing <= v2[ind]) {
                if (greatest_missing == v2[ind]) --greatest_missing;
                --ind;
            }

            if (greatest_missing == -1) cout << ans << '\n';
            else cout << ans + greatest_missing << '\n';
        }
    }

    return 0;
}