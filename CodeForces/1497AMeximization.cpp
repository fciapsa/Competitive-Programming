#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

struct par {
    int x, y;
    bool operator<(par const& other) const {
        if (y < other.y) return true;
        else if (y > other.y) return false;
        else return x < other.x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    
    int tc, n, x;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<par> v(n);
        vector<bool> marked(101, false);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (marked[x]) v[i] = { x,2 };
            else {
                marked[x] = true;
                v[i] = { x,1 };
            }
        }
        sort(v.begin(), v.end());

        cout << v[0].x;
        for (int i = 1; i < n; ++i) cout << ' ' << v[i].x;
        cout << '\n';
    }

return 0;
}