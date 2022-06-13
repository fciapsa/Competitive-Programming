#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(int b, int n, int e, int sb, int sn, int se, vector<int> const& cs, int mn) {
    int ind = 0;
    while (ind < cs.size()) {
        if (b >= 2 && 2 * sb * cs[ind] >= mn) {
            ++ind;
            b -= 2;
        }
        else if (b && n && (sb + sn) * cs[ind] >= mn) {
            ++ind;
            --b;
            --n;
        }     
        else {
            if (2 * sn > sb + se) {//try b+e first
                if (b && e && (sb + se) * cs[ind] >= mn) {
                    ++ind;
                    --b;
                    --e;
                }
                else if (n >= 2 && 2 * sn * cs[ind] >= mn) {
                    ++ind;
                    n -= 2;
                }
                else if (n && e && (sn + se) * cs[ind] >= mn) {
                    ++ind;
                    --n;
                    --e;
                }
                else if (e >= 2 && 2 * se * cs[ind] >= mn) {
                    ++ind;
                    e -= 2;
                }
                else break;
            }
            else {//try n+n first
                if (n >= 2 && 2 * sn * cs[ind] >= mn) {
                    ++ind;
                    n -= 2;
                }
                else if (b && e && (sb + se) * cs[ind] >= mn) {
                    ++ind;
                    --b;
                    --e;
                }
                else if (n && e && (sn + se) * cs[ind] >= mn) {
                    ++ind;
                    --n;
                    --e;
                }
                else if (e >= 2 && 2 * se * cs[ind] >= mn) {
                    ++ind;
                    e -= 2;
                }
                else break;
            }
        }
    }

    return ind == cs.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    int b, n, e, sb, sn, se;
    cin >> b >> n >> e >> sb >> sn >> se;

    int m = (b + n + e) / 2;
    vector<int> cs(m);
    for (int i = 0; i < m; ++i) cin >> cs[i];
    sort(cs.begin(), cs.end(), greater<int>());


    int low = cs[m - 1] * 2 * sb, high = cs[0] * 2 * se;
    int mid, ans = low;
    while (low <= high) {
        mid = (low + high) / 2;

        if (check(b, n, e, sb, sn, se, cs, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}