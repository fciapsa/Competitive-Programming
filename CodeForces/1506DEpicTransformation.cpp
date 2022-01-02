#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x, elim, x1, x2;
    cin >> tc;
    while (tc--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++mp[x];
        }

        elim = 0;
        priority_queue<int> pq;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push(it->second);
        }

        while (pq.size() >= 2) {
            x1 = pq.top();
            pq.pop();
            x2 = pq.top();
            pq.pop();

            --x1;
            --x2;
            elim += 2;
            if (x1 > 0) pq.push(x1);
            if (x2 > 0) pq.push(x2);
        }

        cout << n - elim << '\n';
    }

    return 0;
}