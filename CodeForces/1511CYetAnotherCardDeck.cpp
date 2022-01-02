#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int n, q, x, s;
    cin >> n >> q;
    vector<bool> color(51, false);
    vector<int> posIni(51);
    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (!color[x]) {
            color[x] = true;
            dq.push_back(x);
            posIni[x] = i;
        }
    }

    bool first = true;
    s = dq.size();
    while (q--) {
        cin >> x;
        for (int i = 1; i <= s; ++i) {
            if (dq.front() == x) {
                if (color[x]) {//1st extraction
                    color[x] = false;
                    if (first) {
                        first = false;
                        cout << posIni[x];
                    }
                    else cout << ' ' << posIni[x];

                    for(int k = 1; k <= 50; ++k){
                        if (posIni[k] < posIni[x]) ++posIni[k];
                    }
                    dq.pop_front();
                }
                else {
                    cout << ' ' << i;
                    dq.pop_front();
                }
            }
            else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        dq.push_front(x);
    }
    cout << '\n';

    return 0;
}