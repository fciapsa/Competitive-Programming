#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t, n, hills, valls, decrease, upd1, upd2, old;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        vector<char> vs(n, '0');
        hills = 0;
        valls = 0;
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 1; i < n - 1; ++i) {
            if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
                vs[i] = 'h';
                ++hills;
            }
            else if (v[i] < v[i + 1] && v[i] < v[i - 1]) {
                vs[i] = 'v';
                ++valls;
            }
        }

        decrease = 0;
        for (int i = 1; i < n - 1; ++i) {
            old = 0;
            for (int ind = i - 1; ind <= i + 1; ++ind) if (vs[ind] != '0') ++old;
            upd1 = 0;//make v[i] = v[i-1]
            if (i + 1 < n - 1 && ((v[i + 1] < v[i + 2] && v[i + 1] < v[i - 1]) || (v[i + 1] > v[i + 2] && v[i + 1] > v[i - 1]))) ++upd1;
            if (upd1 < old && old - upd1 > decrease) decrease = old - upd1;

            upd2 = 0;//make v[i] = v[i+1]
            if (i - 1 > 0 && ((v[i - 1] < v[i - 2] && v[i - 1] < v[i + 1]) || (v[i - 1] > v[i - 2] && v[i - 1] > v[i + 1]))) ++upd2;
            if (upd2 < old && old - upd2 > decrease) decrease = old - upd2;
        }

        cout << hills + valls - decrease << '\n';
    }
return 0;
}